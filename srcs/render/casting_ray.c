/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:30:53 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/17 15:36:40 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	reset_flag_n_door(t_game *game)
{
	game->ray->flag = 0;
	game->ray->door_h = 0;
	game->ray->door_v = 0;
}

void	init_angle_n_door(t_game *game, int *ray)
{
	*ray = 0;
	game->ray->ray_a = game->player->angle - (game->player->fov_rd / 2);
	game->ray->door = 0;
}

void	cast_rays(t_game *game)
{
	double	h_inter;
	double	v_inter;
	int		ray;

	init_angle_n_door(game, &ray);
	while (ray < WIN_WIDTH)
	{
		reset_flag_n_door(game);
		v_inter = get_v_inter(game, nor_angle(game->ray->ray_a));
		h_inter = get_h_inter(game, nor_angle(game->ray->ray_a));
		if (v_inter <= h_inter)
		{
			game->ray->dist = v_inter;
			game->ray->door = game->ray->door_v;
		}
		else
		{
			game->ray->dist = h_inter;
			game->ray->door = game->ray->door_h;
			game->ray->flag = 1;
		}
		render_wall(game, ray);
		ray++;
		game->ray->ray_a += (game->player->fov_rd / WIN_WIDTH);
	}
}
