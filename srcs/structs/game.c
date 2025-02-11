/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:36:46 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/11 22:02:29 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	*init_game(void)
{
	t_game	*game;

	game = (t_game *) ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	return (game);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	free_map(game->map);
	free(game->north_texture);
	free(game->south_texture);
	free(game->west_texture);
	free(game->east_texture);
	free(game->floor_color);
	free(game->celling_color);
	free(game);
	game = NULL;
}
