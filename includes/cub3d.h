/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:58:07 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/13 01:01:46 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include "MLX42/MLX42.h"
# include "libft.h"
# include "messages.h"

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
	t_list		*errors;
}	t_game;

/*** Core */
// Errors
void		add_error(t_game *game, char *msg);
void		show_errors(t_game *game);
void		quit(t_game *game, int exit_code);

/*** Parsing */
// Game
void		handle_game(t_game *game, char *file);

// Map
void		handle_map(t_game *game, int map_fd);
void		process_map(t_game *game);
void		reset_map(t_game *game);
void		set_map_size(t_game *game);
void		justify_map_lines(t_game *game);

// Textures
bool		check_textures(t_game *game);
void		handle_invalid_textures(t_game *game, char *texture,
				char *direction);
void		handle_missing_textures(t_game *game);
bool		handle_texture(t_game *game, char *raw_line);
void		handle_textures(t_game *game, int map_fd);

// Colors
t_color		*handle_color(char *str_color);

// Utils
bool		is_map_char(char c);
int			remove_end_newline_and_spaces(char *str);
bool		is_valid_extension(char *file, char *extension);
char		**map_list_to_map_array(t_list *lst);

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
uint32_t	rgba_to_uint(int r, int g, int b, int a);

// Arrays
void		array_free(char **array);
int			array_len(char **array);

#endif
