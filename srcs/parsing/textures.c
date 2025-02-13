/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:31:07 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/13 05:47:17 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parse_texture(t_game *game, char *line, char *id,
	mlx_texture_t **texture_ptr)
{
	if (*texture_ptr)
	{
		add_error(game, ft_strjoin(id, DUPLICATE_TEXTURE_MSG));
		return ;
	}
	if (!is_valid_extension(line + ft_strlen(id), TEXTURE_EXT))
	{
		add_error(game, ft_strjoin(id, INVALID_TEXTURE_EXT_MSG));
		return ;
	}
	*texture_ptr = mlx_load_png(line + ft_strlen(id));
	if (!(*texture_ptr))
		add_error(game, ft_strjoin(id, INVALID_TEXTURE_MSG));
}

static void	parse_color(t_game *game, char *line, char *id, t_color **color)
{
	if (*color)
	{
		add_error(game, ft_strjoin(id, DUPLICATE_COLOR_MSG));
		return ;
	}
	*color = handle_color(line + ft_strlen(id));
	if (!(*color))
	{
		add_error(game, ft_strjoin(id, INVALID_COLOR_MSG));
		*color = uint_to_t_color(0x00000000);
	}
}

/*** Return false if char map found */
static bool	handle_texture(t_game *game, char *raw_line)
{
	char	*line;

	line = ft_strtrim(raw_line, " ");
	if (!line)
		return (add_error(game, MALLOC_ERROR_MSG), false);
	if (ft_strncmp(line, NORTH_ID, 3) == 0)
		parse_texture(game, line, NORTH_ID, &game->textures->north);
	else if (ft_strncmp(line, SOUTH_ID, 3) == 0)
		parse_texture(game, line, SOUTH_ID, &game->textures->south);
	else if (ft_strncmp(line, WEST_ID, 3) == 0)
		parse_texture(game, line, WEST_ID, &game->textures->west);
	else if (ft_strncmp(line, EAST_ID, 3) == 0)
		parse_texture(game, line, EAST_ID, &game->textures->east);
	else if (ft_strncmp(line, DOOR_ID, 3) == 0)
		parse_texture(game, line, DOOR_ID, &game->textures->door);
	else if (ft_strncmp(line, FLOOR_ID, 2) == 0)
		parse_color(game, line, FLOOR_ID, &game->textures->floor);
	else if (ft_strncmp(line, CELLING_ID, 2) == 0)
		parse_color(game, line, CELLING_ID, &game->textures->celling);
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
	while (line && !check_textures(game->textures))
	{
		if (remove_end_newline_and_spaces(line))
		{
			add_error(game, ft_strdup(INVALID_TEXTURE_LINE_MSG));
			break ;
		}
		if (!handle_texture(game, line))
		{
			handle_missing_textures(game);
			if (ft_lstsize(game->errors) == 0)
				add_error(game, ft_strdup(MAP_BEFORE_TEXTURES_MSG));
			break ;
		}
		if (check_textures(game->textures))
			break ;
		free(line);
		line = get_next_line(map_fd);
	}
	free(line);
}
