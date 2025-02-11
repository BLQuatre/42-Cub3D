/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:53:33 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/11 19:32:46 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_reles(mlx_key_data_t keydata, t_mlx *mlx)
{
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_RELEASE))
		mlx->player->l_r = 0;
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_RELEASE))
		mlx->player->l_r = 0;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_RELEASE))
		mlx->player->u_d = 0;
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_RELEASE))
		mlx->player->u_d = 0;
	else if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_RELEASE))
		mlx->player->rot = 0;
	else if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_RELEASE))
		mlx->player->rot = 0;
}

void	mlx_key(mlx_key_data_t keydata, void *ml)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ml;
	if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS || \
	keydata.action == MLX_REPEAT))
		ft_exit(ml);
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS))
		mlx->player->l_r = -1;
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS))
		mlx->player->l_r = 1;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS))
		mlx->player->u_d = -1;
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		mlx->player->u_d = 1;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		mlx->player->rot = -1;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		mlx->player->rot = 1;
	ft_reles(keydata, mlx);
}

void	rotate_player(t_mlx *mlx, int i)
{
	if (i == 1)
	{
		mlx->player->angle += ROT_SPEED;
		if (mlx->player->angle > 2 * M_PI)
			mlx->player->angle -= 2 * M_PI;
	}
	else
	{
		mlx->player->angle -= ROT_SPEED;
		if (mlx->player->angle < 0)
			mlx->player->angle += 2 * M_PI;
	}
}

void	move_player(t_mlx *mlx, double move_x, double move_y)
{
	int	map_grid_y;
	int	map_grid_x;
	int	new_x;
	int	new_y;

	new_x = round(mlx->player->plyr_x + move_x);
	new_y = round(mlx->player->plyr_y + move_y);
	map_grid_x = ((new_x)/ TILE_SIZE);
	map_grid_y = ((new_y)/ TILE_SIZE);
	// printf("y : %d, x : %d\n", mlx->player->l_r, mlx->player->u_d);
	if (mlx->game->map->map[map_grid_y][map_grid_x] != '1' && \
	(mlx->game->map->map[map_grid_y][(int)((mlx->player->plyr_x + move_x - 1) / TILE_SIZE)] != '1' && \
	mlx->game->map->map[(int)((mlx->player->plyr_y + move_y - 1) / TILE_SIZE)][map_grid_x] != '1'))
	{
		mlx->player->plyr_x = new_x;
		mlx->player->plyr_y = new_y;
	}
}

void	hook(t_mlx *mlx, double move_x, double move_y)
{
	if (mlx->player->rot == 1)
		rotate_player(mlx, 1);
	if (mlx->player->rot == -1)
		rotate_player(mlx, 0);
	if (mlx->player->l_r == 1)
	{
		move_x = -sin(mlx->player->angle) * P_SPEED;
		move_y = cos(mlx->player->angle) * P_SPEED;
	}
	if (mlx->player->l_r == -1)
	{
		move_x = sin(mlx->player->angle) * P_SPEED;
		move_y = -cos(mlx->player->angle) * P_SPEED;
	}
	if (mlx->player->u_d == 1)
	{
		move_x = cos(mlx->player->angle) * P_SPEED;
		move_y = sin(mlx->player->angle) * P_SPEED;
	}
	if (mlx->player->u_d == -1)
	{
		move_x = -cos(mlx->player->angle) * P_SPEED;
		move_y = -sin(mlx->player->angle) * P_SPEED;
	}
	move_player(mlx, move_x, move_y);
}
