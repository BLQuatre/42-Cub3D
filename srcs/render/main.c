/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:50:59 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/10 20:00:00 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_game *scammed(void)
{
	t_game *gm = ft_calloc(1, sizeof(t_game));
	gm->map = ft_calloc(1, sizeof(t_map));
	gm->map->map = ft_calloc(10, sizeof(char *));
	gm->map->map[0] = ft_strdup("1111111111111111111111111"); //fill the map
	gm->map->map[1] = ft_strdup("1000000000000000000000001");
	gm->map->map[2] = ft_strdup("10111111111000000000000011111111111111");
	gm->map->map[3] = ft_strdup("101       1000000000000011111111111111");
	gm->map->map[4] = ft_strdup("10111111111000000000000000000000000001");
	gm->map->map[5] = ft_strdup("10000000000000000000000011111111111111");
	gm->map->map[6] = ft_strdup("1000000000000000000000001");
	gm->map->map[7] = ft_strdup("10000000000000000000000P1");
	gm->map->map[8] = ft_strdup("1111111111111111111111111");
	gm->map->map[9] = NULL;
	gm->map->start_pos.y = 7;
	gm->map->start_pos.x = 23;
	gm->map->max_h = 9;
	gm->map->max_w = 28;
	gm->south_texture = ft_strdup("./assets/soink.png");
	gm->north_texture = ft_strdup("./assets/cat.png");
	gm->east_texture = ft_strdup("./assets/poker.png");
	gm->west_texture = ft_strdup("./assets/bob.png");
	gm->floor_color = uint_to_t_color(0x00000000);
	gm->celling_color = uint_to_t_color(0x00000000);
	return (gm);
}

int main(void)
{
	// t_data	*data;
	t_game	*game;

	game = scammed();
	// data = init_argument();
	start_the_game(game);
	return (0);
}