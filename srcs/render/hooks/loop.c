/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:12:26 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/14 11:20:26 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	loop_hook(void *game_ptr)
{
	t_game	*game;

	game = (t_game *) game_ptr;
	// mlx_set_mouse_pos(game->mlx, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	movements_hook(game, 0, 0);
	animation_hook(game);
	cast_rays(game);
	mini_map(game);
}
