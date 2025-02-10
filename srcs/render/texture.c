/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:31:34 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/10 20:38:07 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

mlx_texture_t	*get_texture(t_mlx *mlx, int flag)
{
	mlx->ray->ray_a = nor_angle(mlx->ray->ray_a);
	if (flag == 0)
	{
		if (mlx->ray->ray_a > M_PI / 2 && mlx->ray->ray_a < 3 * (M_PI / 2))
			return (mlx->texture->we);
		else
			return (mlx->texture->ea);
	}
	else
	{
		if (mlx->ray->ray_a > 0 && mlx->ray->ray_a < M_PI)
			return (mlx->texture->so);
		else
			return (mlx->texture->no);
	}
}

int reverse_bytes(int c)
{
	unsigned int 	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b); 
}