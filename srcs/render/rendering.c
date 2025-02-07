/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:14:16 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/07 20:38:55 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	if (x < 0)
		return ;
	else if (x >= WIN_WIDTH)
		return ;
	if (y < 0)
		return ;
	else if (y >= WIN_HEIGHT)
		return ;
	mlx_put_pixel(mlx->img, x, y, color);
}

float nor_angle(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

void	draw_floor_ceiling(t_mlx *mlx, int ray, int t_pix, int b_pix)
{
	int i;
	// int c;

	i = b_pix;
	while (i < WIN_HEIGHT)
		my_mlx_pixel_put(mlx, ray, i++, 0xB99470FF);
	i = 0;
	while (i < t_pix)
		my_mlx_pixel_put(mlx, ray, i++, 0x89CFF3FF);
}

int get_color(t_mlx *mlx, int flag)
{
	mlx->ray->ray_a = nor_angle(mlx->ray->ray_a);
	if (flag == 0)
	{
		if (mlx->ray->ray_a > M_PI / 2 && mlx->ray->ray_a < 3 * (M_PI / 2))
			return (0xB5B5B5FF);
		else
			return (0xB5B5B5FF);
	}
	else
	{
		if (mlx->ray->ray_a > 0 && mlx->ray->ray_a < M_PI)
			return (0xF5F5F5FF);
		else
			return (0xF5F5F5FF);
	}
}

void	draw_wall(t_mlx *mlx, int ray, int t_pix, int b_pix)
{
	int color;

	color = get_color(mlx, mlx->ray->flag);
	while (t_pix < b_pix)
		my_mlx_pixel_put(mlx, ray, t_pix++, color);
}

void	render_wall(t_mlx *mlx, int ray)
{
	double	wall_h;
	double	b_pix;
	double	t_pix;

	mlx->ray->dist *= cos(nor_angle(mlx->ray->ray_a - mlx->player->angle));
	wall_h = (TILE_SIZE / mlx->ray->dist) * ((WIN_WIDTH / 2) / tan(mlx->player->fov_rd / 2));
	b_pix = (WIN_HEIGHT / 2) + (wall_h / 2);
	t_pix = (WIN_HEIGHT / 2) - (wall_h / 2);
	if (b_pix > WIN_HEIGHT)
		b_pix = WIN_HEIGHT;
	if (t_pix < 0)
		t_pix = 0;
	draw_wall(mlx, ray, t_pix, b_pix);
	draw_floor_ceiling(mlx, ray, t_pix, b_pix); 
}