/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:22:51 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/21 16:24:12 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	save_tile(t_game *game, t_vector pos)
{
	if (game->map->tiles[pos.y][pos.x] == NORTH
		|| game->map->tiles[pos.y][pos.x] == SOUTH
		|| game->map->tiles[pos.y][pos.x] == WEST
		|| game->map->tiles[pos.y][pos.x] == EAST)
	{
		if (game->map->start_pos.x != 0 || game->map->start_pos.y != 0)
			return (add_error(game, ft_strdup(DUPLICATE_START_MSG)));
		game->map->start_pos.x = pos.x;
		game->map->start_pos.y = pos.y;
	}
}

static void	is_map_block_valid(t_game *game)
{
	t_vector	pos;

	pos.y = 0;
	while (game->map->tiles[pos.y])
	{
		pos.x = 0;
		while (game->map->tiles[pos.y][pos.x])
		{
			if (is_map_char(game->map->tiles[pos.y][pos.x]))
				save_tile(game, pos);
			else if (game->map->tiles[pos.y][pos.x] != ' ')
				add_error(game, ft_strdup(INVALID_CHAR_MSG));
			pos.x++;
		}
		pos.y++;
	}
	if (game->map->start_pos.x == 0 || game->map->start_pos.y == 0)
		add_error(game, ft_strdup(MISSING_COMPONENT_MSG));
}

// dont forget to put player pos again
static bool	is_map_path_valid(t_game *game, int x, int y)
{
	int		north;
	int		south;
	int		east;
	int		west;
	char	tile;

	if (ft_lstsize(game->errors) > 0)
		return (false);
	tile = game->map->tiles[y][x];
	if (tile == ' ' || y == 0 || x == 0 || y >= game->map->max_h - 1)
		return (add_error(game, ft_strdup(INVALID_PATH_MSG)), false);
	if (tile == WALL || tile == (PATH * -1) || tile == (DOOR * -1))
		return (false);
	if (tile == PATH || tile == DOOR)
		game->map->tiles[y][x] *= -1;
	north = is_map_path_valid(game, x, y - 1);
	south = is_map_path_valid(game, x, y + 1);
	east = is_map_path_valid(game, x + 1, y);
	west = is_map_path_valid(game, x - 1, y);
	if (north || south || east || west)
		return (true);
	return (false);
}

void	process_map(t_game *game)
{
	char	player_start_id;

	set_map_size(game);
	justify_map_lines(game);
	is_map_block_valid(game);
	if (ft_lstsize(game->errors) > 0)
		return ;
	player_start_id
		= game->map->tiles[game->map->start_pos.y][game->map->start_pos.x];
	game->map->tiles[game->map->start_pos.y][game->map->start_pos.x] = PATH;
	is_map_path_valid(game, game->map->start_pos.x, game->map->start_pos.y);
	if (ft_lstsize(game->errors) > 0)
		return ;
	reset_map(game);
	game->map->tiles[game->map->start_pos.y][game->map->start_pos.x]
		= player_start_id;
}
