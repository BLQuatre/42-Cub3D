/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:31:34 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/10 21:01:45 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_exit(void *ml)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ml;
	int	i = 0;
	while (mlx->game->map->map[i])
		free(mlx->game->map->map[i++]);
	
	// free_game(mlx->game);
	free(mlx->game->map->map);
	free(mlx->game->map);
	free(mlx->game->celling_color);
	free(mlx->game->east_texture);
	free(mlx->game->floor_color);
	free(mlx->game->north_texture);
	free(mlx->game->south_texture);
	free(mlx->game->west_texture);
	mlx_delete_texture(mlx->texture->ea);
	mlx_delete_texture(mlx->texture->no);
	mlx_delete_texture(mlx->texture->so);
	mlx_delete_texture(mlx->texture->we);
	free(mlx->texture);
	free(mlx->game);
	free(mlx->player);
	free(mlx->ray);
	mlx_delete_image(mlx->mlx_p, mlx->img);
	mlx_close_window(mlx->mlx_p);
	mlx_terminate(mlx->mlx_p);
	free(mlx);
	exit (0);
}