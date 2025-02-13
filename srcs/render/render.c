/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:27:19 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/13 16:31:27 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
	init_hooks(game);
	mlx_loop(game->mlx);
}
