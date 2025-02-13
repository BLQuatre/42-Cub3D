/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:14:28 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/13 01:00:20 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <fcntl.h>
# include <stdio.h>
# include "cub3d.h"
# include "libft.h"
# include "get_next_line.h"

# define FILE_EXT ".cub"
# define TEXTURE_EXT ".png"
# define MAP_CHARS "10DNSEW"

typedef enum e_texture_char
{
	NORTH = 'N',
	SOUTH = 'S',
	WEST = 'W',
	EAST = 'E',
	WALL = '1',
	PATH = '0',
	DOOR = 'D'
}	t_texture_char;

# define NORTH_ID "NO "
# define SOUTH_ID "SO "
# define WEST_ID "WE "
# define EAST_ID "EA "
# define FLOOR_ID "F "
# define CELLING_ID "C "

#endif
