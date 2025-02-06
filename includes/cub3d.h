/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:58:07 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/06 19:46:41 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42/MLX42.h"

typedef struct s_vector
{
	int	x;
	int	y;
	int	h;
}	t_vector;

typedef struct s_map
{
	char		**map;
	t_vector	start_pos;
}	t_map;

typedef struct s_game
{
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	uint32_t	floor_color;
	uint32_t	celling_color;
	t_map		map;
}	t_game;

#endif
