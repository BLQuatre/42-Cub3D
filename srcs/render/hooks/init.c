/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:57:48 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/13 16:13:11 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	init_hooks(t_game *game)
{
	mlx_loop_hook(game->mlx, loop_hook, game);
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_close_hook(game->mlx, close_hook, game);
	mlx_mouse_hook(game->mlx, mouse_hook, game);
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	mlx_cursor_hook(game->mlx, cursor_hook, game);
}
