/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:01:48 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/13 16:31:08 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	key_release(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_RELEASE))
		game->player->l_r = 0;
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_RELEASE))
		game->player->l_r = 0;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_RELEASE))
		game->player->u_d = 0;
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_RELEASE))
		game->player->u_d = 0;
	else if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_RELEASE))
		game->player->rot = 0;
	else if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_RELEASE))
		game->player->rot = 0;
}

void	key_hook(mlx_key_data_t keydata, void *game_ptr)
{
	t_game	*game;

	game = (t_game *) game_ptr;
	if (keydata.key == MLX_KEY_ESCAPE
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		quit(game, 0);
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS))
		game->player->l_r = -1;
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS))
		game->player->l_r = 1;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS))
		game->player->u_d = -1;
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		game->player->u_d = 1;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		game->player->rot = -1;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		game->player->rot = 1;
	key_release(keydata, game);
}
