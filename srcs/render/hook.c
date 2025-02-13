/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:53:33 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/13 15:43:08 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_reles(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_RELEASE))
		game->player->l_r = 0;
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_RELEASE))
		game->player->l_r = 0;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_RELEASE))
		game->player->u_d = 0;
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_RELEASE))
		game->player->u_d = 0;
	else if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_RELEASE))
		game->player->rot = 0;
	else if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_RELEASE))
		game->player->rot = 0;
}

void	mlx_key(mlx_key_data_t keydata, void *game_ptr)
{
	t_game	*game;

	game = (t_game *) game_ptr;
	if (keydata.key == MLX_KEY_ESCAPE &&
		(keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		quit(game, 0);
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS))
		game->player->l_r = -1;
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS))
		game->player->l_r = 1;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS))
		game->player->u_d = -1;
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		game->player->u_d = 1;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		game->player->rot = -1;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		game->player->rot = 1;
	ft_reles(keydata, game);
}

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

void	hook(t_game *game, double move_x, double move_y)
{
	if (game->player->rot == 1)
		rotate_player(game, 1);
	if (game->player->rot == -1)
		rotate_player(game, 0);
	if (game->player->l_r == 1)
	{
		move_x = -sin(game->player->angle) * P_SPEED;
		move_y = cos(game->player->angle) * P_SPEED;
	}
	if (game->player->l_r == -1)
	{
		move_x = sin(game->player->angle) * P_SPEED;
		move_y = -cos(game->player->angle) * P_SPEED;
	}
	if (game->player->u_d == 1)
	{
		move_x = cos(game->player->angle) * P_SPEED;
		move_y = sin(game->player->angle) * P_SPEED;
	}
	if (game->player->u_d == -1)
	{
		move_x = -cos(game->player->angle) * P_SPEED;
		move_y = -sin(game->player->angle) * P_SPEED;
	}
	move_player(game, move_x, move_y);
}
