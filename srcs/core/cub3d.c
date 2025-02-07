/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:25:58 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/07 19:07:27 by cauvray          ###   ########.fr       */
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
		if (line && (ft_strlen(line) - 1) == '\n')
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
		return ("NO");
	else if (texture_place == SOUTH)
		return ("SO");
	else if (texture_place == WEST)
		return ("WE");
	else if (texture_place == EAST)
		return ("EA");
	else if (texture_place == FLOOR)
		return ("F");
	else if (texture_place == CELLING)
		return ("C");
	return (NULL);
}

bool	set_texture(char **dest, char *texture)
{
	if (*dest)
		return false;
	*dest = texture;
	return (true);

}

char	*parse_texture(t_texture_place texture_place, t_list *str_map)
{
	char *texture_id = get_texture_identifier(texture_place);
	if (!texture_id)
		return (NULL);

	while (str_map->next)
	{
		char **test = ft_split((char *) str_map->content, ' ');


		if (test[0] && ft_strncmp(test[0], texture_id, 3) == 0)
		{
			printf("|1|%s|2|\n", test[0]);
			printf("|1|%s|2|\n", test[1]);
		}


		int i =0;
		while (test[i]) {
			free(test[i]);
			i++;
		}
		free(test);
		str_map = str_map->next;
	}

	return (NULL);
}




// void	parse_textures(t_game *game, t_list	*map_str)
// {
// 	bool	dup_flag;

// 	while (map_str)
// 	{
// 		if (set_texture(&game->north_texture, parse_texture(NORTH, (char *) map_str->content))
// 		|| set_texture(&game->south_texture, parse_texture(SOUTH, (char *) map_str->content))
// 		|| set_texture(&game->north_texture, parse_texture(NORTH, (char *) map_str->content))
// 		|| set_texture(&game->north_texture, parse_texture(NORTH, (char *) map_str->content))
// 		||)
// 	}
// }







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

	parse_texture(NORTH, str_map);

	ft_lstclear(&str_map, free);
	free(game);
	return (0);
}
