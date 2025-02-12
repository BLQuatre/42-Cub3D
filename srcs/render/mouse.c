/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:54:39 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/12 22:22:59 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	mouse(mouse_key_t button, action_t action, modifier_key_t mod, void *ml)
{
	(void)mod;
	(void)ml;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
		printf("here\n");
}

void	cursor_mouse(double xpos, double ypos, void *ml)
{
	t_mlx *mlx;

	(void)ypos;
	mlx = (t_mlx *)ml;
	if(xpos)
	{
		mlx_set_mouse_pos(mlx->mlx_p, WIN_WIDTH / 2, WIN_HEIGHT / 2);
		if ((WIN_WIDTH / 2) - xpos < -5)
		{
			// mlx->player->rot = 1;
			rotate_player(mlx, 1);
			move_player(mlx, 0, 0);
			// mlx_set_mouse_pos(mlx->mlx_p, WIN_WIDTH / 2, WIN_HEIGHT / 2);
			// printf("test\n");
		}
		else if ((WIN_WIDTH / 2) - xpos > 5)
		{
			// mlx->player->rot = -1;
			rotate_player(mlx, 0);
			move_player(mlx, 0, 0);
		}
		// mlx->player->rot = 0;
	}
		// printf("test\n");
	// else if ((WIN_WIDTH / 2) - xpos > 0)
	// {
	// 	rotate_player(mlx, 1);
	// 	// move_player(mlx, 0, 0);
	// }

	printf("%f\n", xpos);
	// mlx_set_mouse_pos(mlx->mlx_p, WIN_WIDTH / 2, WIN_HEIGHT / 2);
}