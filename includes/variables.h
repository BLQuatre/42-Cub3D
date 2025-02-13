                                                 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:49:59 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/13 15:31:07 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLES_H
# define VARIABLES_H

# ifndef WIN_WIDTH
#  define WIN_WIDTH 500
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 500
# endif

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define TILE_SIZE 30
# define FOV 60
# define ROT_SPEED 0.05
# define P_SPEED 4

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
# define DOOR_ID "DO "

#endif
