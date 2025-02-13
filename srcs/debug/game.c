/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:56:23 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/13 04:56:11 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	debug_show_game(t_game *game)
{
	char	buffer[27];

	debug(GREEN, "GAME", "t_game: (%p)", game);
	if (!game)
		return ;
	debug(GREEN, "GAME", "{");
	debug(GREEN, "GAME", "\tnorth_texture: `%s`", game->textures->north);
	debug(GREEN, "GAME", "\tsouth_texture: `%s`", game->textures->south);
	debug(GREEN, "GAME", "\twest_texture: `%s`", game->textures->west);
	debug(GREEN, "GAME", "\teast_texture: `%s`", game->textures->east);
	debug(GREEN, "GAME", "\tdoor_texture: `%s`", game->textures->door);
	debug_get_color_str(t_color_to_uint(game->textures->floor), buffer);
	debug(GREEN, "GAME", "\tfloor_color: `%s` (%u)",
		buffer, t_color_to_uint(game->textures->floor));
	debug_get_color_str(t_color_to_uint(game->textures->celling), buffer);
	debug(GREEN, "GAME", "\tcelling_color: `%s` (%u)",
		buffer, t_color_to_uint(game->textures->celling));
	debug(GREEN, "GAME", "\tmap: (%p)", game->map);
	debug(GREEN, "GAME", "}");
}
