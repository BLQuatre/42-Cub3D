/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:19:52 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/23 15:11:05 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_game(t_game *game, char *file)
{
	int		map_fd;

	map_fd = open(file, O_RDONLY);
	if (map_fd < 0)
	{
		add_error(game, ft_strdup(CANNOT_OPEN_FILE_MSG));
		quit(game, 1);
	}
	handle_textures(game, map_fd);
	if (ft_lstsize(game->errors) == 0 && check_textures(game->textures))
		handle_map(game, map_fd);
	get_next_line(-1);
	close(map_fd);
	load_animations(game);
	if (ft_lstsize(game->errors) > 0 || !check_textures(game->textures))
		quit(game, 1);
}
