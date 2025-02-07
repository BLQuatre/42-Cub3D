/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:31:34 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/07 20:34:34 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_exit(t_mlx *mlx)
{
	int 	i = 0;
	while (mlx->dt->map2d[i])
		free(mlx->dt->map2d[i++]);
	free(mlx->dt->map2d);
	free(mlx->dt);
	free(mlx->player);
	free(mlx->ray);
	mlx_delete_image(mlx->mlx_p, mlx->img);
	mlx_close_window(mlx->mlx_p);
	mlx_terminate(mlx->mlx_p);
	exit(0);
}