/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:36:46 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/21 21:50:42 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *) ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->start_pos.x = -1;
	map->start_pos.y = -1;
	return (map);
}

void	free_map(t_map *map)
{
	if (!map)
		return ;
	array_free(map->tiles);
	free(map);
	map = NULL;
}
