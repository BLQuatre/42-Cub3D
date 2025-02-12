/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:25:58 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/12 01:35:29 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"
#include "debug.h"

static bool	is_valid_args(int ac, char **av, t_game *game)
{
	if (ac != 2)
		return (add_error(&game->errors, ft_strdup(USAGE_ERROR_MSG)), false);
	if (!is_valid_extension(av[1], FILE_EXT))
		return (add_error(&game->errors,
				ft_strdup(INVALID_MAP_EXT_MSG)), false);
	return (true);
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = init_game();
	if (!is_valid_args(ac, av, game))
		quit(game, 1);
	handle_game(game, av[1]);
	quit(game, 0);
}
