/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:06:45 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/17 14:20:23 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	close_open_door(float x, float y, t_game *game, char c)
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
		if (game->map->tiles[y_m][x_m] == c)
		{
			game->map->tiles[y_m][x_m] = c * -1;
			return (0);
		}
	}
	return (1);
}

void	close_open_h(t_game *game, float angl, char c)
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
	while (close_open_door(h_x, h_y - pixel, game, c))
	{
		h_x += x_step;
		h_y += y_step;
	}
}

void	close_open_v(t_game *game, float angl, char c)
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
	while (close_open_door(v_x - pixel, v_y, game, c))
	{
		v_x += x_step;
		v_y += y_step;
	}
}

void	door_action_v(t_game *game, double v, double mid_a)
{
	double	dist;

	dist = v * cos(nor_angle(game->ray->ray_a - game->player->angle));
	if (game->door->open_v && dist > 2 && dist < 90)
		close_open_v(game, mid_a, 'D' * -1);
	else if (game->door->close_v && dist > 2 && dist < 90)
		close_open_v(game, mid_a, 'D');
}

void	door_action_h(t_game *game, double h, double mid_a)
{
	double	dist;

	dist = h * cos(nor_angle(game->ray->ray_a - game->player->angle));
	if (game->door->open_h && dist > 2 && dist < 90)
		close_open_h(game, mid_a, 'D' * -1);
	else if (game->door->close_h && dist > 2 && dist < 90)
		close_open_h(game, mid_a, 'D');
}
