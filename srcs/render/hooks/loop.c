/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:12:26 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/13 16:16:53 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	loop_hook(void *game_ptr)
{
	t_game	*game;

	game = (t_game *) game_ptr;
	// mlx_set_mouse_pos(game->mlx, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	movements_hook(game, 0, 0);
	cast_rays(game);
}
