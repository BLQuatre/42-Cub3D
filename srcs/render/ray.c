/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:00:08 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/17 15:38:19 by jbergos          ###   ########.fr       */
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
	if ((y_m >= game->map->max_h || x_m >= game->map->max_w))
		return (0);
	if (game->map->tiles[y_m] && x_m <= (int) ft_strlen(game->map->tiles[y_m]))
	{
		if (game->map->tiles[y_m][x_m] == '1' \
			|| game->map->tiles[y_m][x_m] == 'D')
		{
			if (game->map->tiles[y_m][x_m] == 'D')
			{
				game->ray->door = 1;
				return (0);
			}
			else
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
	h_y = floor(game->player->pos.y / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angl, &h_y, &y_step, 1);
	h_x = game->player->pos.x + (h_y - game->player->pos.y) / tan(angl);
	if ((unit_circle(angl, 'y') && x_step > 0)
		|| (!unit_circle(angl, 'y') && x_step < 0))
		x_step *= -1;
	game->ray->door = 0;
	while (wall_hit(h_x, h_y - pixel, game))
		add_step(&h_x, &h_y, x_step, y_step);
	if (game->ray->door == 1)
		game->ray->door_h = 1;
	game->ray->h_x = h_x;
	game->ray->h_y = h_y;
	return (sqrt(pow(h_x - game->player->pos.x, 2)
			+ pow(h_y - game->player->pos.y, 2)));
}

float	get_v_inter(t_game *game, float angl)
{
	float	v_x;
	float	v_y;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(angl);
	v_x = floor(game->player->pos.x / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angl, &v_x, &x_step, 0);
	v_y = game->player->pos.y + (v_x - game->player->pos.x) * tan(angl);
	if ((unit_circle(angl, 'x') && y_step < 0) || \
	(!unit_circle(angl, 'x') && y_step > 0))
		y_step *= -1;
	game->ray->door = 0;
	while (wall_hit(v_x - pixel, v_y, game))
		add_step(&v_x, &v_y, x_step, y_step);
	if (game->ray->door == 1)
		game->ray->door_v = 1;
	game->ray->v_x = v_x;
	game->ray->v_y = v_y;
	return (sqrt(pow(v_x - game->player->pos.x, 2) + \
	pow(v_y - game->player->pos.y, 2)));
}
