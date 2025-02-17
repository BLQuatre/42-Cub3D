/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:12:26 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/17 14:45:06 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	loop_hook(void *game_ptr)
{
	t_game	*game;

	game = (t_game *) game_ptr;
	movements_hook(game, 0, 0);
	animation_hook(game);
	cast_rays(game);
	mini_map(game);
}
