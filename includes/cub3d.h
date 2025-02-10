/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:58:07 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/10 13:50:47 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include "MLX42/MLX42.h"
# include "libft.h"

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_color
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
}	t_color;

typedef struct s_map
{
	char		**map;
	int			max_w;
	int			max_h;
	t_vector	start_pos;
}	t_map;

typedef struct s_game
{
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	t_color		*floor_color;
	t_color		*celling_color;
	t_map		*map;
}	t_game;

/*** Structs */
// Game
t_game		*init_game(void);
void		free_game(t_game *game);

// Map
t_map		*init_map(void);
void		free_map(t_map *map);

/*** UTILS */
// Colors
t_color		*uint_to_t_color(const uint32_t rgba);
uint32_t	t_color_to_uint(const t_color *color);

// Arrays
void		array_free(char **array);
int			array_len(char **array);

#endif
