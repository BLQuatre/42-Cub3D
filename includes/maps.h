/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:14:28 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/07 17:50:16 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_H
# define MAPS_H

# include <fcntl.h>
# include "cub3d.h"
# include "libft.h"
# include "get_next_line.h"

# define FILE_EXT ".cub"

typedef enum e_texture_place {
	NORTH,
	SOUTH,
	WEST,
	EAST,
	FLOOR,
	CELLING
}	t_texture_place;

#endif
