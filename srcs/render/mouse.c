/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:54:39 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/13 05:41:19 by cauvray          ###   ########.fr       */
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
	if (xpos)
	{
		mlx_set_mouse_pos(game->mlx, WIN_WIDTH / 2, WIN_HEIGHT / 2);
		if ((WIN_WIDTH / 2) - xpos < -5)
		{
			// game->player->rot = 1;
			rotate_player(game, 1);
			move_player(game, 0, 0);
			// mlx_set_mouse_pos(game->mlx, WIN_WIDTH / 2, WIN_HEIGHT / 2);
			// printf("test\n");
		}
		else if ((WIN_WIDTH / 2) - xpos > 5)
		{
			// game->player->rot = -1;
			rotate_player(game, 0);
			move_player(game, 0, 0);
		}
		// game->player->rot = 0;
	}
		// printf("test\n");
	// else if ((WIN_WIDTH / 2) - xpos > 0)
	// {
	// 	rotate_player(game, 1);
	// 	// move_player(game, 0, 0);
	// }

	printf("%f\n", xpos);
	// mlx_set_mouse_pos(game->mlx, WIN_WIDTH / 2, WIN_HEIGHT / 2);
}