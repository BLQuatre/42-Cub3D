/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:27:19 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/13 15:30:32 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void	game_loop(void *game_ptr)
{
	t_game	*game;

	game = (t_game *) game_ptr;
	// mlx_set_mouse_pos(game->mlx, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	hook(game, 0, 0);
	cast_rays(game);
}

double	get_player_angle(t_map *map)
{
	char	tile;

	tile = map->tiles[map->start_pos.y][map->start_pos.x];
	if (tile == 'N')
		return ((3 * M_PI) / 2);
	else if (tile == 'S')
		return (M_PI / 2);
	else if (tile == 'E')
		return (0);
	else
		return (M_PI);
}

void	load_player(t_game *game)
{
	game->player->pos.x = game->map->start_pos.x * TILE_SIZE + TILE_SIZE / 2;
	game->player->pos.y = game->map->start_pos.y * TILE_SIZE + TILE_SIZE / 2;
	game->player->fov_rd = (FOV * M_PI) / 180;
	game->player->angle = get_player_angle(game->map);
}

void close_window(void *game_ptr)
{
	t_game	*game;

	game = (t_game *) game_ptr;
	quit(game, 0);
}

void	load_game(t_game *game)
{
	game->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Cub3d", 0);
	if (!game->mlx)
	{
		add_error(game, ft_strdup(MALLOC_ERROR_MSG));
		quit(game, 1);
	}
	load_player(game);
	game->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_key_hook(game->mlx, mlx_key, game);
	mlx_close_hook(game->mlx, close_window, game);
	mlx_mouse_hook(game->mlx, mouse, game);
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	mlx_cursor_hook(game->mlx, cursor_mouse, game);
	mlx_loop(game->mlx);
}
