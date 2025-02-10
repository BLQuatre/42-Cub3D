/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:27:19 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/10 19:59:39 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void	game_loop(void *ml)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ml;
	// mlx_delete_image(mlx->mlx_p, mlx->img);
	// mlx->img = mlx_new_image(mlx->mlx_p, WIN_WIDTH, WIN_HEIGHT);
	hook(mlx, 0, 0);
	cast_rays(mlx);
	// mlx_image_to_window(mlx->mlx_p, mlx->img, 0, 0);
}

void	init_the_player(t_mlx *mlx)
{
	mlx->player->plyr_x = mlx->game->map->start_pos.x * TILE_SIZE + TILE_SIZE / 2;
	mlx->player->plyr_y = mlx->game->map->start_pos.y * TILE_SIZE + TILE_SIZE / 2;
	mlx->player->fov_rd = (FOV * M_PI) / 180;
	mlx->player->angle = ( 3 * M_PI) / 2; // angle de vue du joueur;
	// north = M_PI / 2;
	// EAST = 0;
	// WEST = M_PI;
	// SOUTH = (3 * M_PI) / 2 ;
}
#include <stdio.h>
void	init_texture(t_mlx *mlx)
{
	// t_texture	*texture;

	// texture = ft_calloc(1, sizeof(t_texture));
	// printf("here\n");
	mlx->texture->no = mlx_load_png(mlx->game->north_texture);
	if (!mlx->texture->no)
	{
		printf("no\n");
		exit(1);
	}
	mlx->texture->so = mlx_load_png(mlx->game->south_texture);
	if (!mlx->texture->so)
	{
		printf("so\n");
		exit(1);
	}
	mlx->texture->we = mlx_load_png(mlx->game->west_texture);
	if (!mlx->texture->we)
	{
		printf("we\n");
		exit(1);
	}
	mlx->texture->ea = mlx_load_png(mlx->game->east_texture);
	if (!mlx->texture->ea)
	{
		printf("ea\n");
		exit(1);
	}
	// return (texture);
}

void	start_the_game(t_game *game)
{
	t_mlx	*mlx;

	// mlx.dt = dt;
	mlx = ft_calloc(1, sizeof(t_mlx));
	// mlx->texture = init_texture(mlx);
	mlx->game = game;
	mlx->texture = ft_calloc(1, sizeof(t_texture));
	init_texture(mlx);
	mlx->player = ft_calloc(1, sizeof(t_player));
	mlx->ray = ft_calloc(1, sizeof(t_ray));
	mlx->mlx_p = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Cub3d", 0);
	init_the_player(mlx);
	mlx->img = mlx_new_image(mlx->mlx_p, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(mlx->mlx_p, mlx->img, 0, 0);
	mlx_loop_hook(mlx->mlx_p, game_loop, mlx);
	mlx_key_hook(mlx->mlx_p, mlx_key, mlx);
	mlx_close_hook(mlx->mlx_p, ft_exit, mlx);
	mlx_loop(mlx->mlx_p);
}