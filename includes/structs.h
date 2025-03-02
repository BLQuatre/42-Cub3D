/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 04:29:09 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/13 21:07:05 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "MLX42/MLX42.h"
# include "libft.h"
# include "variables.h"

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

// *** MAP
typedef struct s_map
{
	char		**tiles;
	int			max_w;
	int			max_h;
	t_vector	start_pos;
}	t_map;

t_map		*init_map(void);
void		free_map(t_map *map);

// *** TEXTURES
typedef struct s_textures
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
	mlx_texture_t	*door;
	t_color			*floor;
	t_color			*celling;
}	t_textures;

t_textures	*init_textures(void);
void		free_textures(t_textures *textures);

// *** PLAYER
typedef struct s_player
{
	t_vector	pos;
	double		angle;
	float		fov_rd;
	int			rot;
	int			l_r;
	int			u_d;
}	t_player;

t_player	*init_player(void);
void		free_player(t_player *player);

// *** RAY
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
}	t_ray;

t_ray		*init_ray(void);
void		free_ray(t_ray *ray);

// *** ACTION DOOR
typedef struct s_act_door
{
	int	open;
	int	close;
	int	open_h;
	int	open_v;
	int	close_h;
	int	close_v;
}	t_act_door;

t_act_door	*init_act_door(void);
void		reset_act_door(t_act_door *door);
void		free_act_door(t_act_door *door);

// *** FRAME
typedef struct s_frame
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;
	int				duration;
}	t_frame;

t_frame		*init_frame(void);
void		free_frame(t_frame *frame, mlx_t *mlx);

// *** ANIMATION
typedef struct s_animation
{
	t_frame	*frames[ANIM_SIZE + 1];
	int		frame_index;
	int		frame_duration;
	int		last_frame_index;
}	t_animation;

t_animation	*init_animation(void);
void		free_animation(t_animation *animation, mlx_t *mlx);

// *** GAME
// TODO: Test to remove ptr on t_ray and t_player struct
typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_ray			*ray;
	t_player		*player;
	t_map			*map;
	t_textures		*textures;
	t_animation		*animation;
	t_list			*errors;
	t_act_door		*door;
}	t_game;

t_game		*init_game(void);
void		free_game(t_game *game);

#endif
