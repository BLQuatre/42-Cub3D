/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:49:59 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/12 22:08:48 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# ifndef WIN_WIDTH
#  define WIN_WIDTH 500
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 500
# endif

# include "cub3d.h"
# include <stdlib.h>
# include "libft.h"
# define _USE_MATH_DEFINES
# include <math.h>
# include <string.h>
#include <stdio.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define TILE_SIZE 30
# define FOV 60
# define ROT_SPEED 0.0095
# define P_SPEED 4

typedef struct s_player
{
	int		plyr_x;
	int		plyr_y;
	double	angle;
	float	fov_rd;
	int		rot;
	int		l_r;
	int		u_d;
}	t_player;

typedef struct s_ray
{
	double	ray_a;
	double	dist;
	double	h_x;
	double	h_y;
	double	v_x;
	double	v_y;
	int		index;
	int		flag;
	int		door_h;
	int		door_v;
	int		door;
} t_ray;

typedef struct s_texture
{
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*ea;
	mlx_texture_t	*we;
	mlx_texture_t	*door;
} t_texture;

typedef struct s_mlx
{
	mlx_image_t	*img;
	mlx_t		*mlx_p;
	t_ray		*ray;
	t_game		*game;
	t_player	*player;
	t_texture	*texture;
}	t_mlx;

void	game_loop(void *ml);
void	init_the_player(t_mlx *mlx);
void	start_the_game(t_game *game);
int		unit_circle(float angle, char c);
int		inter_check(float angle, float *inter, float *step, int is_horizon);
int		wall_hit(float x, float y, t_mlx *mlx);
float	get_h_inter(t_mlx *mlx, float angl);
float	get_v_ibnter(t_mlx *mlx, float angl);
void	cast_rays(t_mlx *mlx);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
float 	nor_angle(float angle);
void	draw_floor_ceiling(t_mlx *mlx, int ray, int t_pix, int b_pix);
int		get_color(t_mlx *mlx, int flag);
void	draw_wall(t_mlx *mlx, int t_pix, int b_pix, double wall_h);
void	render_wall(t_mlx *mlx, int ray);
void	ft_reles(mlx_key_data_t keydata, t_mlx *mlx);
void	mlx_key(mlx_key_data_t keydata, void *ml);
void	rotate_player(t_mlx *mlx, int i);
void	move_player(t_mlx *mlx, double move_x, double move_y);
void	hook(t_mlx *mlx, double move_x, double move_y);
void	ft_exit(void *v_mlx);
void	add_texture(t_mlx *mlx);
mlx_texture_t	*get_texture(t_mlx *mlx, int flag);
int reverse_bytes(int c);
void	mouse(mouse_key_t button, action_t action, modifier_key_t mod, void *ml);
void	cursor_mouse(double xpos, double ypos, void *ml);
#endif