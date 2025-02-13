/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:49:59 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/13 19:31:07 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"
# define _USE_MATH_DEFINES
# include <math.h>

# include <stdio.h>

// *** Render
void			load_player(t_game *game);
void			load_game(t_game *game);
double			get_player_angle(t_map *map);

// *** HOOKS
void			init_hooks(t_game *game);
void			loop_hook(void *game_ptr);
void			key_hook(mlx_key_data_t keydata, void *game_ptr);
void			close_hook(void *game_ptr);
void			mouse_hook(mouse_key_t button, action_t action,
					modifier_key_t mod, void *game_ptr);
void			cursor_hook(double xpos, double ypos, void *game_ptr);
void			movements_hook(t_game *game, double move_x, double move_y);
void			animation_hook(t_game *game);

// *** Movements
void			rotate_player(t_game *game, int i);
void			move_player(t_game *game, double move_x, double move_y);

// *** RAY
int				unit_circle(float angle, char c);
int				inter_check(float angle, float *inter, float *step,
					int is_horizon);
int				wall_hit(float x, float y, t_game *game);
float			get_h_inter(t_game *game, float angl);
float			get_v_ibnter(t_game *game, float angl);
void			cast_rays(t_game *game);

// *** RENDERING
void			draw_floor_ceiling(t_game *game, int ray, int t_pix, int b_pix);
void			draw_wall(t_game *game, int t_pix, int b_pix, double wall_h);
void			render_wall(t_game *game, int ray);
void			my_mlx_pixel_put(t_game *game, int x, int y, int color);
float			nor_angle(float angle);
double			get_x_o(mlx_texture_t *texture, t_game *game);
int				reverse_bytes(int c);

// *** TEXTURES
mlx_texture_t	*get_texture(t_game *game, int flag);

#endif
