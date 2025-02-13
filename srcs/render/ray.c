/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:00:08 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/13 05:10:40 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	unit_circle(float angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < M_PI)
			return (1);
	}
	else if (c == 'y')
	{
		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
			return (1);
	}
	return (0);
}

int	inter_check(float angle, float *inter, float *step, int is_horizon)
{
	if (is_horizon)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2))
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

int	wall_hit(float x, float y, t_game *game)
{
	int	x_m;
	int	y_m;

	if (x <= 0 || y <= 0)
		return (0);
	x_m = floor(x / TILE_SIZE);
	y_m = floor(y / TILE_SIZE);
	// game->ray->door = 0;
	if ((y_m >= game->map->max_h || x_m >= game->map->max_w))
		return (0);
	if (game->map->tiles[y_m] && x_m <= \
	(int)strlen(game->map->tiles[y_m]))
		if (game->map->tiles[y_m][x_m] == '1' || game->map->tiles[y_m][x_m] == 'D')
		{
			if (game->map->tiles[y_m][x_m] == 'D')
			{
				game->ray->door = 1;
				return (0);
			}
			else
			{
				// game->ray->door = 0;
				return (0);
			}
		}
	return (1);
}

float	get_h_inter(t_game *game, float angl)
{
	float	h_x;
	float	h_y;
	float	x_step;
	float	y_step;
	int		pixel;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angl);
	h_y = floor(game->player->plyr_y / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angl, &h_y, &y_step, 1);
	h_x = game->player->plyr_x + (h_y - game->player->plyr_y) / tan(angl);
	if ((unit_circle(angl, 'y') && x_step > 0)
		|| (!unit_circle(angl, 'y') && x_step < 0))
		x_step *= -1;
	game->ray->door = 0;
	while (wall_hit(h_x, h_y - pixel, game))
	{
		h_x += x_step;
		h_y += y_step;
	}
	if (game->ray->door == 1)
		game->ray->door_h = 1;
	game->ray->h_x = h_x;
	game->ray->h_y = h_y;
	return (sqrt(pow(h_x - game->player->plyr_x, 2)
		+ pow(h_y - game->player->plyr_y, 2)));
}

float	get_v_ibnter(t_game *game, float angl)
{
	float	v_x;
	float	v_y;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(angl);
	v_x = floor(game->player->plyr_x / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angl, &v_x, &x_step, 0);
	v_y = game->player->plyr_y + (v_x - game->player->plyr_x) * tan(angl);
	if ((unit_circle(angl, 'x') && y_step < 0) || \
	(!unit_circle(angl, 'x') && y_step > 0))
		y_step *= -1;
	game->ray->door = 0;
	while (wall_hit(v_x - pixel, v_y, game))
	{
		v_x += x_step;
		v_y += y_step;
	}
	if (game->ray->door == 1)
		game->ray->door_v = 1;
	game->ray->v_x = v_x;
	game->ray->v_y = v_y;
	return (sqrt(pow(v_x - game->player->plyr_x, 2) + \
	pow(v_y - game->player->plyr_y, 2)));
}

void	cast_rays(t_game *game)
{
	double	h_inter;
	double	v_inter;
	int		ray;

	ray = 0;
	game->ray->ray_a = game->player->angle - (game->player->fov_rd / 2);
	game->ray->door = 0;
	while (ray < WIN_WIDTH)
	{
		game->ray->flag = 0;
		game->ray->door_h = 0;
		game->ray->door_v = 0;
		v_inter = get_v_ibnter(game, nor_angle(game->ray->ray_a));
		h_inter = get_h_inter(game, nor_angle(game->ray->ray_a));
		if (v_inter <= h_inter)
		{
			game->ray->dist = v_inter;
			game->ray->door = game->ray->door_v;
		}
		else
		{
			game->ray->dist = h_inter;
			game->ray->door = game->ray->door_h;
			game->ray->flag = 1;
		}
		render_wall(game, ray);
		// game->ray->door = 0;
		ray++;
		game->ray->ray_a += (game->player->fov_rd / WIN_WIDTH);
	}
}
