/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:53:33 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/21 12:40:35 by jbergos          ###   ########.fr       */
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
	}
	else
	{
		game->player->angle -= ROT_SPEED;
		if (game->player->angle < 0)
			game->player->angle += 2 * M_PI;
	}
}

int	is_move_in_door(t_game *game, int new_x, int new_y)
{
	if (game->map->tiles[new_y / TILE_SIZE][new_x / TILE_SIZE] != 'D'
		&& (game->map->tiles[new_y / TILE_SIZE]
			[(int)((game->player->pos.x) / TILE_SIZE)] != 'D'
		&& game->map->tiles[(int)((game->player->pos.y)
			/ TILE_SIZE)][new_x / TILE_SIZE] != 'D'))
	{
		if (game->map->tiles[new_y / TILE_SIZE][new_x / TILE_SIZE] != 'D'
			&& (game->map->tiles[new_y / TILE_SIZE]
				[(int)((new_x - 1) / TILE_SIZE)] != 'D'
			&& game->map->tiles[(int)((new_y - 1)
				/ TILE_SIZE)][new_x / TILE_SIZE] != 'D'))
			return (1);
	}
	return (0);
}

int	is_move_in_wall(t_game *game, int new_x, int new_y)
{
	if (game->map->tiles[new_y / TILE_SIZE][new_x / TILE_SIZE] != '1'
		&& (game->map->tiles[new_y / TILE_SIZE]
			[(int)((game->player->pos.x) / TILE_SIZE)] != '1'
		&& game->map->tiles[(int)((game->player->pos.y)
			/ TILE_SIZE)][new_x / TILE_SIZE] != '1'))
	{
		if (game->map->tiles[new_y / TILE_SIZE][new_x / TILE_SIZE] != '1'
			&& (game->map->tiles[new_y / TILE_SIZE]
				[(int)((new_x - 1) / TILE_SIZE)] != '1'
			&& game->map->tiles[(int)((new_y - 1)
				/ TILE_SIZE)][new_x / TILE_SIZE] != '1'))
			return (1);
	}
	return (0);
}

void	move_player(t_game *game, double move_x, double move_y)
{
	int	new_x;
	int	new_y;

	new_x = round(game->player->pos.x + move_x);
	new_y = round(game->player->pos.y + move_y);
	if (is_move_in_wall(game, new_x, new_y) && \
		is_move_in_door(game, new_x, new_y))
	{
		game->player->pos.x = new_x;
		game->player->pos.y = new_y;
	}
}
