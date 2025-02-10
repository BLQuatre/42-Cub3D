/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:03:08 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/10 13:56:00 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "cub3d.h"
# include <stdarg.h>
# include <stdio.h>

typedef enum e_debug_color
{
	BLACK,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	WHITE,
	BRIGHT_BLACK,
	BRIGHT_RED,
	BRIGHT_GREEN,
	BRIGHT_YELLOW,
	BRIGHT_BLUE,
	BRIGHT_MAGENTA,
	BRIGHT_CYAN,
	BRIGHT_WHITE
}	t_debug_color;

void	debug(t_debug_color color, const char *tag, const char *format, ...);

void	debug_get_color_str(uint32_t rgba, char buffer[27]);

void	debug_show_vector(t_vector *vector);

void	debug_show_map(t_map *map);

void	debug_show_game(t_game *game);

#endif
