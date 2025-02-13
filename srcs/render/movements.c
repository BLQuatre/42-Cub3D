/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:53:33 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/13 16:19:15 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	rotate_player(t_game *game, int i)
{
	if (i == 1)
	{
		game->player->angle += ROT_SPEED;
		if (game->player->angle > 2 * M_PI)
			game->player->angle -= 2 * M_PI;
		// game->player->rot = 0;
	}
	else
	{
		game->player->angle -= ROT_SPEED;
		if (game->player->angle < 0)
			game->player->angle += 2 * M_PI;
		// game->player->rot = 0;
	}
}

void	move_player(t_game *game, double move_x, double move_y)
{
	int	map_grid_y;
	int	map_grid_x;
	int	new_x;
	int	new_y;

	new_x = round(game->player->pos.x + move_x);
	new_y = round(game->player->pos.y + move_y);
	map_grid_x = new_x / TILE_SIZE;
	map_grid_y = new_y / TILE_SIZE;
	// printf("y : %d, x : %d\n", mlx->player->l_r, mlx->player->u_d);
	if (game->map->tiles[map_grid_y][map_grid_x] != '1'
		&& (game->map->tiles[map_grid_y][(int)((game->player->pos.x + move_x - 1) / TILE_SIZE)] != '1'
		&& game->map->tiles[(int)((game->player->pos.y + move_y - 1) / TILE_SIZE)][map_grid_x] != '1'))
	{
		if (game->map->tiles[map_grid_y][map_grid_x] != 'D'
			&& (game->map->tiles[map_grid_y][(int)((game->player->pos.x + move_x - 1) / TILE_SIZE)] != 'D'
			&& game->map->tiles[(int)((game->player->pos.y + move_y - 1) / TILE_SIZE)][map_grid_x] != 'D'))
		{
			game->player->pos.x = new_x;
			game->player->pos.y = new_y;
		}
	}
}
