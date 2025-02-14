/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:58:04 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/14 12:00:17 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	draw_tiles_mini_map(t_game *game, int x, int y, int color)
{
	int	x_m;
	int	y_m;

	y_m = y;
	x_m = x;
	while (y_m < (y + (TILE_SIZE / 2)))
	{
		while (x_m < (x + (TILE_SIZE /2)))
			my_mlx_pixel_put(game, x_m++, y_m, color);
		y_m++;
		x_m = x;
	}
}

void	draw_player(t_game *game)
{
	int x;
	int	y;

	x = game->player->pos.x / TILE_SIZE;
	y = game->player->pos.y / TILE_SIZE;
	y *= (TILE_SIZE / 2);
	x *= (TILE_SIZE / 2);
	draw_tiles_mini_map(game, x, y, RED);

}

void	mini_map(t_game *game)
{
	int	y;
	int	x;
	int	x_p;
	int	y_p;

	y = 0;
	y_p = 0;
	while (y < game->map->max_h)
	{
		x = 0;
		x_p = 0;
		while (game->map->tiles[y][x])
		{
			if (game->map->tiles[y][x] == '1')
				draw_tiles_mini_map(game, x_p, y_p , GREY);
			else if (game->map->tiles[y][x] == 'D')
				draw_tiles_mini_map(game, x_p, y_p, BLU);
			else if (game->map->tiles[y][x] == 'D' * -1)
				draw_tiles_mini_map(game, x_p, y_p, ORNG);
			else
				draw_tiles_mini_map(game, x_p, y_p, WHI);
			x++;
			x_p += TILE_SIZE / 2;

		}
		y++;
		y_p += TILE_SIZE / 2;
	}
	draw_player(game);
}