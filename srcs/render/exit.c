/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:31:34 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/10 15:04:22 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_exit(void *ml)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ml;
	int 	i = -1;
	while (++i < 10)
	{
		free(mlx->game->maps->map[i]);
	}
	free(mlx->game->maps->map);
	free(mlx->game->maps);
	free(mlx->game);
	free(mlx->player);
	free(mlx->ray);
	mlx_delete_image(mlx->mlx_p, mlx->img);
	mlx_close_window(mlx->mlx_p);
	mlx_terminate(mlx->mlx_p);
	free(mlx);
	exit (0);
}