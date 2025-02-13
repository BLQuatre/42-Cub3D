/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:54:39 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/13 16:10:19 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	mouse_hook(mouse_key_t button, action_t action, modifier_key_t mod,
	void *game_ptr)
{
	(void) mod;
	(void) game_ptr;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
		printf("here\n");
}
