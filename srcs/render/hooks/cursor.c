/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:10:13 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/13 16:10:30 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	cursor_hook(double xpos, double ypos, void *game_ptr)
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