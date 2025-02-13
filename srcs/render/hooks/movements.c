/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:53:33 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/13 16:18:03 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	movements_hook(t_game *game, double move_x, double move_y)
{
	if (game->player->rot == 1)
		rotate_player(game, 1);
	if (game->player->rot == -1)
		rotate_player(game, 0);
	if (game->player->l_r == 1)
	{
		move_x = -sin(game->player->angle) * P_SPEED;
		move_y = cos(game->player->angle) * P_SPEED;
	}
	if (game->player->l_r == -1)
	{
		move_x = sin(game->player->angle) * P_SPEED;
		move_y = -cos(game->player->angle) * P_SPEED;
	}
	if (game->player->u_d == 1)
	{
		move_x = cos(game->player->angle) * P_SPEED;
		move_y = sin(game->player->angle) * P_SPEED;
	}
	if (game->player->u_d == -1)
	{
		move_x = -cos(game->player->angle) * P_SPEED;
		move_y = -sin(game->player->angle) * P_SPEED;
	}
	move_player(game, move_x, move_y);
}
