/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:36:46 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/13 21:07:22 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	*init_game(void)
{
	t_game	*game;

	game = (t_game *) ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = init_map();
	game->textures = init_textures();
	game->player = init_player();
	game->ray = init_ray();
	game->door = init_act_door();
	game->animation = init_animation();
	return (game);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	free_map(game->map);
	free_textures(game->textures);
	free_player(game->player);
	free_ray(game->ray);
	free_act_door(game->door);
	free_animation(game->animation, game->mlx);
	if (game->mlx)
	{
		mlx_delete_image(game->mlx, game->img);
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
	}
	free(game);
	game = NULL;
}
