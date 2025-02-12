/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:19:52 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/12 01:38:09 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

static void	remove_end_newline(char *line)
{
	int	newline_i;

	if (!line || !line[0])
		return ;
	newline_i = ft_strlen(line) - 1;
	if (line[newline_i] == '\n')
		line[newline_i] = '\0';
}

// debug(GREEN, "GAME", "Line: `%s`", line);
void	handle_game(t_game *game, char *file)
{
	int		map_fd;
	char	*line;

	map_fd = open(file, O_RDONLY);
	if (map_fd < 0)
	{
		add_error(&game->errors, ft_strdup(CANNOT_OPEN_FILE_MSG));
		quit(game, 1);
	}
	line = get_next_line(map_fd);
	while (line)
	{
		remove_end_newline(line);
		if (check_textures(game))
		{
			// parsing map
		}
		else
		{
			if (!handle_texture(game, line))
			{
				handle_missing_textures(game);
				if (ft_lstsize(game->errors) == 0)
					add_error(&game->errors,
						ft_strdup(MAP_BEFORE_TEXTURES_MSG));
				break ;
			}
		}
		free(line);
		line = get_next_line(map_fd);
	}
	free(line);
	get_next_line(-1);
	close(map_fd);
	if (ft_lstsize(game->errors) > 0 || !check_textures(game))
		quit(game, 1);
}
