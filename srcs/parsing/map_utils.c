/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:22:51 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/13 04:57:16 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	reset_map(t_game *game)
{
	t_vector	pos;

	pos.y = 0;
	while (game->map->tiles[pos.y])
	{
		pos.x = 0;
		while (game->map->tiles[pos.y][pos.x])
		{
			if (game->map->tiles[pos.y][pos.x] == (PATH * -1)
				|| game->map->tiles[pos.y][pos.x] == (DOOR * -1))
				game->map->tiles[pos.y][pos.x] *= -1;
			pos.x++;
		}
		pos.y++;
	}
}

void	set_map_size(t_game *game)
{
	int		i;
	size_t	max;

	game->map->max_h = array_len(game->map->tiles);
	max = 0;
	i = 0;
	while (game->map->tiles[i])
	{
		if (ft_strlen(game->map->tiles[i]) > max)
			max += ft_strlen(game->map->tiles[i]);
		i++;
	}
	game->map->max_w = max;
}

void	justify_map_lines(t_game *game)
{
	int		i;
	char	*tmp;

	i = 0;
	while (game->map->tiles[i])
	{
		tmp = ft_calloc(game->map->max_w + 1, sizeof(char));
		ft_memset(tmp, ' ', game->map->max_w);
		ft_memcpy(tmp, game->map->tiles[i], ft_strlen(game->map->tiles[i]));
		free(game->map->tiles[i]);
		game->map->tiles[i] = tmp;
		i++;
	}
}
