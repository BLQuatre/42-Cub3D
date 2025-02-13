/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:56:23 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/12 20:17:35 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "parsing.h"

void	debug_show_game(t_game *game)
{
	char	buffer[27];

	debug(GREEN, "GAME", "t_game: (%p)", game);
	if (!game)
		return ;
	debug(GREEN, "GAME", "{");
	debug(GREEN, "GAME", "\tnorth_texture: `%s`", game->north_texture);
	debug(GREEN, "GAME", "\tsouth_texture: `%s`", game->south_texture);
	debug(GREEN, "GAME", "\twest_texture: `%s`", game->west_texture);
	debug(GREEN, "GAME", "\teast_texture: `%s`", game->east_texture);
	debug_get_color_str(t_color_to_uint(game->floor_color), buffer);
	debug(GREEN, "GAME", "\tfloor_color: `%s` (%u)",
		buffer, t_color_to_uint(game->floor_color));
	debug_get_color_str(t_color_to_uint(game->celling_color), buffer);
	debug(GREEN, "GAME", "\tcelling_color: `%s` (%u)",
		buffer, t_color_to_uint(game->celling_color));
	debug(GREEN, "GAME", "\tmap: (%p)", game->map);
	debug(GREEN, "GAME", "}");
}
