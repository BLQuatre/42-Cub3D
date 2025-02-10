/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:14:28 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/10 14:21:11 by cauvray          ###   ########.fr       */
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

# define NORTH_ID "NO "
# define SOUTH_ID "SO "
# define WEST_ID "WE "
# define EAST_ID "EA "
# define FLOOR_ID "F "
# define CELLING_ID "C "

// typedef enum e_texture_place
// {
// 	NORTH,
// 	SOUTH,
// 	WEST,
// 	EAST,
// 	FLOOR,
// 	CELLING
// }	t_texture_place;

#endif
