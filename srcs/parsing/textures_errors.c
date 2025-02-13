/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:08:19 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/13 04:57:26 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_textures(t_textures *textures)
{
	return (textures
		&& textures->north && textures->south
		&& textures->west && textures->east
		&& textures->door
		&& textures->floor && textures->celling);
}

void	handle_missing_textures(t_game *game)
{
	if (!game->textures->north)
		add_error(game, ft_strjoin(NORTH_ID, MISSING_TEXTURE_MSG));
	if (!game->textures->south)
		add_error(game, ft_strjoin(SOUTH_ID, MISSING_TEXTURE_MSG));
	if (!game->textures->west)
		add_error(game, ft_strjoin(WEST_ID, MISSING_TEXTURE_MSG));
	if (!game->textures->east)
		add_error(game, ft_strjoin(EAST_ID, MISSING_TEXTURE_MSG));
	if (!game->textures->door)
		add_error(game, ft_strjoin(DOOR_ID, MISSING_TEXTURE_MSG));
	if (!game->textures->floor)
		add_error(game, ft_strjoin(FLOOR_ID, MISSING_COLOR_MSG));
	if (!game->textures->celling)
		add_error(game, ft_strjoin(CELLING_ID, MISSING_COLOR_MSG));
}
