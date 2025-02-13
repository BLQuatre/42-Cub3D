/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:14:16 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/13 05:07:35 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	if (x < 0)
		return ;
	else if (x >= WIN_WIDTH)
		return ;
	if (y < 0)
		return ;
	else if (y >= WIN_HEIGHT)
		return ;
	mlx_put_pixel(game->img, x, y, color);
}

float	nor_angle(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

void	draw_floor_ceiling(t_game *game, int ray, int t_pix, int b_pix)
{
	int	i;

	i = b_pix;
	while (i < WIN_HEIGHT)
		my_mlx_pixel_put(game, ray, i++,
			t_color_to_uint(game->textures->floor));
	i = 0;
	while (i < t_pix)
		my_mlx_pixel_put(game, ray, i++,
			t_color_to_uint(game->textures->celling));
}

double	get_x_o(mlx_texture_t *texture, t_game *game)
{
	double	x_o;

	if (game->ray->flag == 1)
		x_o = (int) fmodf((game->ray->h_x * (texture->width / TILE_SIZE)),
			texture->width);
	else
		x_o = (int) fmodf((game->ray->v_y * (texture->width / TILE_SIZE)),
			texture->width);
	return (x_o);
}

void	draw_wall(t_game *game, int t_pix, int b_pix, double wall_h)
{
	double			x_o;
	double			y_o;
	mlx_texture_t	*texture;
	uint32_t		*arr;
	double			factor;

	texture = get_texture(game, game->ray->flag);
	// game->ray->door = 0;
	arr = (uint32_t *)texture->pixels;
	factor = (double)texture->height / wall_h;
	x_o = get_x_o(texture, game);
	y_o = (t_pix - (WIN_HEIGHT / 2) + (wall_h / 2)) * factor;
	if (y_o < 0)
		y_o = 0;
	while (t_pix < b_pix)
	{
		my_mlx_pixel_put(game, game->ray->index, t_pix,
			reverse_bytes(arr[(int) y_o * texture->width + (int) x_o]));
		y_o += factor;
		t_pix++;
	}
}

void	render_wall(t_game *game, int ray)
{
	double	wall_h;
	double	b_pix;
	double	t_pix;

	game->ray->dist *= cos(nor_angle(game->ray->ray_a - game->player->angle));
	// printf("angle %f\n", cos(nor_angle(mlx->player->angle - mlx->ray->ray_a)));
	wall_h = (TILE_SIZE / game->ray->dist) * ((WIN_WIDTH / 2) / \
		tan(game->player->fov_rd / 2));
	// printf("ray angle : %f, player angle : %f\n", mlx->ray->ray_a, mlx->player->angle);
	// printf("ray dist : %f\n", mlx->ray->dist);
	b_pix = (WIN_HEIGHT / 2) + (wall_h / 2);
	t_pix = (WIN_HEIGHT / 2) - (wall_h / 2);
	if (b_pix > WIN_HEIGHT)
		b_pix = WIN_HEIGHT;
	if (t_pix < 0)
		t_pix = 0;
	game->ray->index = ray;
	draw_wall(game, t_pix, b_pix, wall_h);
	draw_floor_ceiling(game, ray, t_pix, b_pix);
}
