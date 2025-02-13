/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:54:39 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/13 15:47:50 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	mouse(mouse_key_t button, action_t action, modifier_key_t mod,
	void *game_ptr)
{
	(void) mod;
	(void) game_ptr;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
		printf("here\n");
}

void	cursor_mouse(double xpos, double ypos, void *game_ptr)
{
	t_game *game;

	game = (t_game *) game_ptr;
	(void) ypos;
	mlx_set_mouse_pos(game->mlx, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	if (xpos)
	{
		game->player->rot = 0;
		if ((WIN_WIDTH / 2) - xpos < -50)
		{
			printf("%d\n", game->player->pos.x);
			game->player->rot = 1;

		}
		else if ((WIN_WIDTH / 2) - xpos > 50)
			game->player->rot = -1;
	}
}