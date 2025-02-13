/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:56:23 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/13 04:45:05 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	debug_show_map(t_map *map)
{
	int	i;

	debug(GREEN, "MAP", "t_map: (%p)", map);
	if (!map)
		return ;
	debug(GREEN, "MAP", "{");
	debug(GREEN, "MAP", "\tmap: (%p)", map->tiles);
	if (map->tiles)
	{
		debug(GREEN, "MAP", "\t{");
		i = -1;
		while (map->tiles[++i])
			debug(GREEN, "MAP", "\t\tmap[%d]: `%s`", i, map->tiles[i]);
		debug(GREEN, "MAP", "\t}");
	}
	debug(GREEN, "VEC", "\tstart_pos: (%p)", map->start_pos);
	debug(GREEN, "MAP", "}");
}
