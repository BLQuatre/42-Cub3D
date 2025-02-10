/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:31:34 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/10 12:14:54 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_exit(t_mlx *mlx)
{
	int 	i = 0;
	while (mlx->game->maps.map[i])
		free(mlx->game->maps.map[i++]);
	free(mlx->game->maps.map);
	free(mlx->game);
	free(mlx->player);
	free(mlx->ray);
	mlx_delete_image(mlx->mlx_p, mlx->img);
	mlx_close_window(mlx->mlx_p);
	mlx_terminate(mlx->mlx_p);
	exit(0);
}