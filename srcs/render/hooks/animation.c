/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:59:58 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/14 11:37:19 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	animation_hook(t_game *game)
{
	if (game->player->l_r == 0 && game->player->u_d == 0
		&& game->player->rot == 0)
	{
		game->animation->frame_duration = 0;
		game->animation->frame_index = 0;
	}
	if (game->animation->frame_index > ANIM_SIZE - 1)
		game->animation->frame_index = 0;
	mlx_image_to_window(game->mlx,
		game->animation->frames[game->animation->frame_index++]->image, WIN_WIDTH - (ANIM_IMG_WIDTH * ANIM_IMG_SCALE), 0);
}
