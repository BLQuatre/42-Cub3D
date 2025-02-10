/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:25:58 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/10 09:48:18 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "maps.h"
#include "debug.h"

void	error(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
}

bool	is_valid_extension(char *file, char *extension)
{
	char	*found_ext;

	found_ext = ft_strrchr(file, '.');
	if (!found_ext)
		return (false);
	return (ft_strncmp(found_ext, extension, ft_strlen(extension) + 1) == 0);
}

bool	is_valid_args(int ac, char **av)
{
	if (ac != 2)
		return (error("Usage: ./cub3d <map.cub>"), false);
	if (!is_valid_extension(av[1], FILE_EXT))
		return (error("Map must be .cub extension"), false);
	return (true);
}

t_list	*preprocess_map(char *file)
{
	int map_fd;
	char *line;
	t_list *head;
	t_list *tmp;

	head = NULL;
	map_fd = open(file, O_RDONLY);
	if (map_fd < 0)
		return (error("Cannot open file"), NULL);
	line = NULL;
	while (line || !head)
	{
		line = get_next_line(map_fd);
		if (line && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		tmp = ft_lstnew(line);
		if (!tmp)
			return (ft_lstclear(&head, free), error("Malloc error"), NULL);
		ft_lstadd_back(&head, tmp);
	}
	close(map_fd);
	return (head);
}


char	*get_texture_identifier(t_texture_place texture_place)
{
	if (texture_place == NORTH)
		return ("NO ");
	else if (texture_place == SOUTH)
		return ("SO ");
	else if (texture_place == WEST)
		return ("WE ");
	else if (texture_place == EAST)
		return ("EA ");
	else if (texture_place == FLOOR)
		return ("F ");
	else if (texture_place == CELLING)
		return ("C ");
	return (NULL);
}

bool	is_map_char(int c)
{
	int i = 0
}

char	*get_line_from_texture(t_texture_place texture_place, char *line)
{
	char	*texture_id;

	texture_id = get_texture_identifier(texture_place);
	if (!texture_id)
		return (NULL);
	while (*line && ft_isspace(*line))
		line++;
	if ()
	if (ft_strncmp(line, texture_id, ft_strlen(texture_id)) == 0)
		return line += ft_strlen(texture_id);
	return (NULL);
}

char *secure_strdup(char *str)
{
	if (!str)
		return (NULL);
	return ft_strdup(str);
}

char	*parse_texture(t_texture_place texture_place, t_list *str_map)
{
	char	*texture_line;

	texture_line = NULL;
	while (str_map->next)
	{
		texture_line = get_line_from_texture(texture_place, str_map->content);
		if (texture_line)
			break;
		str_map = str_map->next;
	}
	if (!texture_line || ft_strlen(texture_line) == 0)
	{
		// free and quit game no make check in parse_textures
	}
	return (texture_line);
}

t_color	*parse_color_texture(char *line)
{
	char	**colors;
	int		tmp_color;

	colors = ft_split(line, ',');
	if (!colors || array_len(colors) != 3)
		return (array_free(colors), NULL);
	tmp_color = ft
	if (ft_atoi())




	printf("Color line: `%s`\n", line);

	return (NULL);
}

void	parse_textures(t_game *game, t_list	*str_map)
{
	game->north_texture = secure_strdup(parse_texture(NORTH, str_map));
	game->south_texture = secure_strdup(parse_texture(SOUTH, str_map));
	game->west_texture = secure_strdup(parse_texture(WEST, str_map));
	game->east_texture = secure_strdup(parse_texture(EAST, str_map));
	game->floor_color = parse_color_texture(parse_texture(FLOOR, str_map));
	game->celling_color = parse_color_texture(parse_texture(CELLING, str_map));

	// switch secure_strdup to isvalidtexture
}

void print_map(t_list *str_map)
{
	while (str_map) {
		printf("MAP: %s\n", (char *) str_map->content);
		str_map = str_map->next;
	}
}

int	main(int ac, char **av)
{
	if (!is_valid_args(ac, av))
		return (1);
	t_list *str_map = preprocess_map(av[1]);
	print_map(str_map);

	t_game *game;
	game = (t_game *) ft_calloc(1, sizeof(t_game));

	parse_textures(game, str_map);

	debug_show_game(game);

	ft_lstclear(&str_map, free);
	free(game);
	return (0);
}
