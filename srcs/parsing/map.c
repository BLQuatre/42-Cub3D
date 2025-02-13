/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:22:51 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/13 04:57:21 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	add_line(t_list **lst, char *line)
{
	t_list	*new;

	new = ft_lstnew(line);
	if (!new)
		return ;
	ft_lstadd_back(lst, new);
}

static void	parse_map(t_game *game, t_list *map)
{
	(void) game;
	while (map && map->content && ft_strlen(map->content) == 0)
		map = map->next;
	game->map->tiles = map_list_to_map_array(map);
	if (!game->map->tiles)
		add_error(game, ft_strdup(MALLOC_ERROR_MSG));
	while (map && map->content && ft_strlen(map->content) > 0)
		map = map->next;
	while (map && map->content && ft_strlen(map->content) == 0)
		map = map->next;
	if (map)
		add_error(game, ft_strdup(EMPTY_LINE_IN_MAP_MSG));
}

void	handle_map(t_game *game, int map_fd)
{
	char	*line;
	t_list	*map_lst;

	line = get_next_line(map_fd);
	map_lst = NULL;
	while (line)
	{
		if (remove_end_newline_and_spaces(line))
			add_error(game, ft_strdup(INVALID_MAP_LINE_MSG));
		add_line(&map_lst, line);
		if (ft_lstsize(game->errors) > 0)
			break ;
		line = get_next_line(map_fd);
	}
	if (ft_lstsize(game->errors) == 0)
		parse_map(game, map_lst);
	if (map_lst)
		ft_lstclear(&map_lst, free);
	process_map(game);
}
