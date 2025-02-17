/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:27:19 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/17 14:54:29 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static double	get_player_angle(t_map *map)
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

static void	load_player(t_game *game)
{
	game->player->pos.x = game->map->start_pos.x * TILE_SIZE + TILE_SIZE / 2;
	game->player->pos.y = game->map->start_pos.y * TILE_SIZE + TILE_SIZE / 2;
	game->player->fov_rd = (FOV * M_PI) / 180;
	game->player->angle = get_player_angle(game->map);
}

static void	load_anim_image(t_game *game)
{
	int	i;

	i = 0;
	while (i < ANIM_SIZE)
	{
		game->animation->frames[i]->image = mlx_texture_to_image(game->mlx,
				game->animation->frames[i]->texture);
		if (!game->animation->frames[i]->image)
			add_error(game, ft_strdup(TEXTURE_LOAD_ERROR_MSG));
		else
			mlx_resize_image(
				game->animation->frames[i]->image,
				(uint32_t) ANIM_IMG_WIDTH * ANIM_IMG_SCALE,
				(uint32_t) ANIM_IMG_HEIGHT * ANIM_IMG_SCALE
				);
		i++;
	}
}

void	load_game(t_game *game)
{
	game->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Cub3d", 0);
	if (!game->mlx)
	{
		add_error(game, ft_strdup(MALLOC_ERROR_MSG));
		quit(game, 1);
	}
	load_anim_image(game);
	if (ft_lstsize(game->errors) > 0)
		quit(game, 1);
	load_player(game);
	game->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	init_hooks(game);
	mlx_loop(game->mlx);
}
