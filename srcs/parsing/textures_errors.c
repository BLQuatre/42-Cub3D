/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:08:19 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/12 11:01:38 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

bool	check_textures(t_game *game)
{
	return (game->north_texture && game->south_texture
		&& game->west_texture && game->east_texture
		&& game->floor_color && game->celling_color);
}

void	handle_invalid_textures(t_game *game, char *texture, char *direction)
{
	if (!texture || ft_strlen(texture) == 0)
		add_error(game, ft_strjoin(direction, INVALID_TEXTURE_MSG));
	else if (!is_valid_extension(texture, TEXTURE_EXT))
		add_error(game, ft_strjoin(direction, INVALID_TEXTURE_EXT_MSG));
}

void	handle_missing_textures(t_game *game)
{
	if (!game->north_texture)
		add_error(game, ft_strjoin(NORTH_ID, MISSING_TEXTURE_MSG));
	if (!game->south_texture)
		add_error(game, ft_strjoin(SOUTH_ID, MISSING_TEXTURE_MSG));
	if (!game->west_texture)
		add_error(game, ft_strjoin(WEST_ID, MISSING_TEXTURE_MSG));
	if (!game->east_texture)
		add_error(game, ft_strjoin(EAST_ID, MISSING_TEXTURE_MSG));
	if (!game->floor_color)
		add_error(game, ft_strjoin(FLOOR_ID, MISSING_COLOR_MSG));
	if (!game->celling_color)
		add_error(game, ft_strjoin(CELLING_ID, MISSING_COLOR_MSG));
}
