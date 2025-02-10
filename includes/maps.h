/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:14:28 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/10 09:34:56 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_H
# define MAPS_H

# include <fcntl.h>
# include "cub3d.h"
# include "libft.h"
# include "get_next_line.h"

# define FILE_EXT ".cub"
# define MAP_CHARS "10DNSEW"

typedef enum e_texture_place
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	FLOOR,
	CELLING
}	t_texture_place;

/*** UTILS */
// Colors
t_color		*uint_to_t_color(const uint32_t rgba);
uint32_t	t_color_to_uint(const t_color *color);

// Arrays
void		array_free(char **array);
int			array_len(char **array);

#endif
