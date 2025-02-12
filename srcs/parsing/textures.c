/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:31:07 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/12 15:20:20 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

static bool	is_map_char(char c)
{
	int	i;

	i = ft_strlen(MAP_CHARS) - 1;
	while (i >= 0)
	{
		if (MAP_CHARS[i] == c)
			return (true);
		i--;
	}
	return (false);
}

/*** Return false if char map found */
bool	handle_texture(t_game *game, char *raw_line)
{
	char	*line;

	line = ft_strtrim(raw_line, " ");
	if (!line)
		return (add_error(game, MALLOC_ERROR_MSG), false);
	if (ft_strncmp(line, NORTH_ID, 3) == 0)
	{
		if (game->north_texture)
			add_error(game, ft_strjoin(NORTH_ID, DUPLICATE_TEXTURE_MSG));
		else
		{
			game->north_texture = ft_strdup(line + 3);
			handle_invalid_textures(game, game->north_texture, NORTH_ID);
		}
	}
	else if (ft_strncmp(line, SOUTH_ID, 3) == 0)
	{
		if (game->south_texture)
			add_error(game, ft_strjoin(SOUTH_ID, DUPLICATE_TEXTURE_MSG));
		else
		{
			game->south_texture = ft_strdup(line + 3);
			handle_invalid_textures(game, game->south_texture, SOUTH_ID);
		}
	}
	else if (ft_strncmp(line, WEST_ID, 3) == 0)
	{
		if (game->west_texture)
			add_error(game, ft_strjoin(WEST_ID, DUPLICATE_TEXTURE_MSG));
		else
		{
			game->west_texture = ft_strdup(line + 3);
			handle_invalid_textures(game, game->west_texture, WEST_ID);
		}
	}
	else if (ft_strncmp(line, EAST_ID, 3) == 0)
	{
		if (game->east_texture)
			add_error(game, ft_strjoin(EAST_ID, DUPLICATE_TEXTURE_MSG));
		else
		{
			game->east_texture = ft_strdup(line + 3);
			handle_invalid_textures(game, game->east_texture, EAST_ID);
		}
	}
	else if (ft_strncmp(line, FLOOR_ID, 2) == 0)
	{
		game->floor_color = handle_color(line + 2);
		if (!game->floor_color)
		{
			add_error(game, ft_strjoin(FLOOR_ID, INVALID_COLOR_MSG));
			game->floor_color = uint_to_t_color(0x00000000);
		}
	}
	else if (ft_strncmp(line, CELLING_ID, 2) == 0)
	{
		game->celling_color = handle_color(line + 2);
		if (!game->celling_color)
		{
			add_error(game, ft_strjoin(CELLING_ID, INVALID_COLOR_MSG));
			game->celling_color = uint_to_t_color(0x00000000);
		}
	}
	else if (is_map_char(*line))
	{
		free(line);
		return (false);
	}
	free(line);
	return (true);
}

void	handle_textures(t_game *game, int map_fd)
{
	char	*line;

	line = get_next_line(map_fd);
	while (line && !check_textures(game))
	{
		remove_end_newline(line);
		if (!handle_texture(game, line))
		{
			handle_missing_textures(game);
			if (ft_lstsize(game->errors) == 0)
				add_error(game, ft_strdup(MAP_BEFORE_TEXTURES_MSG));
			break ;
		}
		if (check_textures(game))
			break;
		free(line);
		line = get_next_line(map_fd);
	}
	free(line);
}
