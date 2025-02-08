/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:27:19 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/08 16:32:05 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void	game_loop(void *ml)
{
	t_mlx	*mlx;

	mlx = ml;
	mlx_delete_image(mlx->mlx_p, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx_p, WIN_WIDTH, WIN_HEIGHT);
	hook(mlx, 0, 0);
	cast_rays(mlx);
	mlx_image_to_window(mlx->mlx_p, mlx->img, 0, 0);
}

void	init_the_player(t_mlx mlx)
{
	mlx.player->plyr_x = mlx.dt->p_x * TILE_SIZE + TILE_SIZE / 2;
	mlx.player->plyr_y = mlx.dt->p_y * TILE_SIZE + TILE_SIZE / 2;
	mlx.player->fov_rd = (FOV * M_PI) / 180;
	mlx.player->angle = (M_PI) / 2; // angle de vue du joueur;
	// north = M_PI / 2;
	// EAST = 0;
	// WEST = M_PI;
	// SOUTH = (3 * M_PI) / 2 ;
}

void	start_the_game(t_data *dt)
{
	t_mlx	mlx;

	mlx.dt = dt;
	mlx.player = ft_calloc(1, sizeof(t_player));
	mlx.ray = ft_calloc(1, sizeof(t_ray));
	mlx.mlx_p = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Cub3d", 1);
	init_the_player(mlx);
	mlx_loop_hook(mlx.mlx_p, &game_loop, &mlx);
	mlx_key_hook(mlx.mlx_p, &mlx_key, &mlx);
	mlx_loop(mlx.mlx_p);
}