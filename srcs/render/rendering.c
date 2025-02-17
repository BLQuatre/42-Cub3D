/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:14:16 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/17 15:39:17 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

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

void	draw_wall(t_game *game, int t_pix, int b_pix, double wall_h)
{
	double			x_o;
	double			y_o;
	mlx_texture_t	*texture;
	uint32_t		*arr;
	double			factor;

	texture = get_texture(game, game->ray->flag);
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
	wall_h = (TILE_SIZE / game->ray->dist) * ((WIN_WIDTH / 2) / \
		tan(game->player->fov_rd / 2));
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
