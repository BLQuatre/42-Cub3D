/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:54:39 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/17 14:42:32 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	wall_hit_door(float x, float y, t_game *game)
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
		if (game->map->tiles[y_m][x_m] == '1'
			|| game->map->tiles[y_m][x_m] == 'D'
			|| game->map->tiles[y_m][x_m] == ('D' * -1))
		{
			if (game->map->tiles[y_m][x_m] == 'D')
			{
				game->door->close = 1;
				return (0);
			}
			else if (game->map->tiles[y_m][x_m] == ('D' * -1))
				return (game->door->open = 1, 0);
		}
	}
	return (1);
}

void	add_step(float *x, float *y, float x_step, float y_step)
{
	*x += x_step;
	*y += y_step;
}

float	get_h(t_game *game, float angl)
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
	game->door->close = 0;
	game->door->open = 0;
	while (wall_hit_door(h_x, h_y - pixel, game))
		add_step(&h_x, &h_y, x_step, y_step);
	if (game->door->close)
		game->door->close_h = 1;
	if (game->door->open)
		game->door->open_h = 1;
	return (sqrt(pow(h_x - game->player->pos.x, 2)
			+ pow(h_y - game->player->pos.y, 2)));
}

float	get_v(t_game *game, float angl)
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
	game->door->close = 0;
	game->door->open = 0;
	while (wall_hit_door(v_x - pixel, v_y, game))
		add_step(&v_x, &v_y, x_step, y_step);
	if (game->door->close)
		game->door->close_v = 1;
	if (game->door->open)
		game->door->open_v = 1;
	return (sqrt(pow(v_x - game->player->pos.x, 2) + \
	pow(v_y - game->player->pos.y, 2)));
}

void	mouse_hook(mouse_key_t button, action_t action, modifier_key_t mod,
	void *game_ptr)
{
	t_game	*game;
	double	mid_a;
	double	v;
	double	h;

	(void) mod;
	game = (t_game *)game_ptr;
	mid_a = (game->player->angle - (game->player->fov_rd / 2) + (M_PI / 6));
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
	{
		v = get_v(game, mid_a);
		h = get_h(game, mid_a);
		if (v <= h)
			door_action_v(game, v, mid_a);
		else
			door_action_h(game, h, mid_a);
		reset_act_door(game->door);
	}
}
