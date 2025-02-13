/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:31:34 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/13 15:56:44 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

mlx_texture_t	*get_texture(t_game *game, int flag)
{
	if (game->ray->door)
		return (game->textures->door);
	game->ray->ray_a = nor_angle(game->ray->ray_a);
	if (flag == 0)
	{
		if (game->ray->ray_a > M_PI / 2 && game->ray->ray_a < 3 * (M_PI / 2))
			return (game->textures->west);
		else
			return (game->textures->east);
	}
	else
	{
		if (game->ray->ray_a > 0 && game->ray->ray_a < M_PI)
			return (game->textures->south);
		else
			return (game->textures->north);
	}
}
