/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:49:59 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/13 05:59:34 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"
# include <stdlib.h>
# include "libft.h"
# define _USE_MATH_DEFINES
# include <math.h>
# include <string.h>
# include <stdio.h>

// typedef struct s_texture
// {
// 	mlx_texture_t	*no;
// 	mlx_texture_t	*so;
// 	mlx_texture_t	*ea;
// 	mlx_texture_t	*we;
// 	mlx_texture_t	*door;
// } t_texture;

// typedef struct s_mlx
// {
// 	mlx_image_t	*img;
// 	mlx_t		*mlx_p;
// 	t_ray		*ray;
// 	t_game		*game;
// 	t_player	*player;
// 	t_texture	*texture;
// }	t_mlx;

void			load_player(t_game *game);
void			load_game(t_game *game);
void			close_window(void *game_ptr);
double			get_player_angle(t_map *map);
void			game_loop(void *game_ptr);

void			mlx_key(mlx_key_data_t keydata, void *game_ptr);
void			ft_reles(mlx_key_data_t keydata, t_game *game);
void			rotate_player(t_game *game, int i);
void			move_player(t_game *game, double move_x, double move_y);
void			hook(t_game *game, double move_x, double move_y);

void			mouse(mouse_key_t button, action_t action, modifier_key_t mod,
					void *game_ptr);
void			cursor_mouse(double xpos, double ypos, void *game_ptr);

int				unit_circle(float angle, char c);
int				inter_check(float angle, float *inter, float *step,
					int is_horizon);
int				wall_hit(float x, float y, t_game *game);
float			get_h_inter(t_game *game, float angl);
float			get_v_ibnter(t_game *game, float angl);
void			cast_rays(t_game *game);

void			my_mlx_pixel_put(t_game *game, int x, int y, int color);
float			nor_angle(float angle);
void			draw_floor_ceiling(t_game *game, int ray, int t_pix, int b_pix);
double			get_x_o(mlx_texture_t *texture, t_game *game);
void			draw_wall(t_game *game, int t_pix, int b_pix, double wall_h);
void			render_wall(t_game *game, int ray);

mlx_texture_t	*get_texture(t_game *game, int flag);
int				reverse_bytes(int c);

#endif
