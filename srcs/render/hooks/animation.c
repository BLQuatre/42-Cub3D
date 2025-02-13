/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:59:58 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/13 20:31:38 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	animation_hook(t_game *game)
{
	if (game->player->l_r == 0 && game->player->u_d == 0
		&& game->player->rot == 0)
	{
		game->animation->frame_index = 0;
		game->animation->frame_duration = 0;
		return ;
	}
	printf("Update Animation\n");
}
