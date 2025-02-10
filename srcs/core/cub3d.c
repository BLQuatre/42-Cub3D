/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:25:58 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/10 15:00:41 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "maps.h"
#include "debug.h"

void	error(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
}

void	quit(t_game *game, char *msg, int exit_code)
{
	error(msg);
	if (msg)
		error(msg);
	exit(exit_code);
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

bool	is_map_char(int c)
{
	int i = 0;
	(void) c;
	return (false);
}

char	*get_line_from_texture(t_game *game, char *line, char *texture_id)
{
	while (*line && ft_isspace(*line))
		line++;
	if (is_map_char(*line)
		&& ft_strncmp(line, texture_id, ft_strlen(texture_id)) != 0)
	{
		quit(game, "Map cannot be befor")
	}
	if (ft_strncmp(line, texture_id, ft_strlen(texture_id)) == 0)
		return line += ft_strlen(texture_id);
	return (NULL);
}

char	*parse_texture(t_game *game, t_list *str_map, char *texture_id)
{
	char	*texture_line;

	texture_line = NULL;
	while (str_map->next)
	{
		texture_line = get_line_from_texture(texture_id, str_map->content);
		if (texture_line)
			break;
		str_map = str_map->next;
	}
	return (texture_line);
}

char	*process_texture(t_game *game, t_list *str_map, char *texture_id)
{
	char	*texture = parse_texture(game, str_map, texture_id);

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
	game->north_texture = process_texture(NORTH, str_map);
	game->south_texture = process_texture(SOUTH, str_map);
	game->west_texture = process_texture(WEST, str_map);
	game->east_texture = process_texture(EAST, str_map);
	game->floor_color = parse_color_texture(parse_texture(FLOOR, str_map));
	game->celling_color = parse_color_texture(parse_texture(CELLING, str_map));

	// show error here if texture is invalid
}


void	process_map(t_game *game, t_list *str_map)
{
	t_list *tmp;

	tmp = str_map;

	while (tmp)
	{
		if
		()



		tmp = tmp->next;
	}

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
