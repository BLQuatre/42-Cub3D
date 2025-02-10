/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:50:59 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/10 11:46:42 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_data *init_argument(void)
{
	t_data	*dt = ft_calloc(1, sizeof(t_data));
	dt->map2d = ft_calloc(10, sizeof(char *));
	dt->map2d[0] = ft_strdup("1111111111111111111111111"); //fill the map
	dt->map2d[1] = ft_strdup("1000000000000000000000001");
	dt->map2d[2] = ft_strdup("10111111111000000000000011111111111111");
	dt->map2d[3] = ft_strdup("101       1000000000000011111111111111");
	dt->map2d[4] = ft_strdup("10111111111000000000000000000000000001");
	dt->map2d[5] = ft_strdup("10000000000000000000000011111111111111");
	dt->map2d[6] = ft_strdup("1000000000000000000000001");
	dt->map2d[7] = ft_strdup("10000000000000000000000P1");
	dt->map2d[8] = ft_strdup("1111111111111111111111111");
	dt->map2d[9] = NULL;
	dt->p_y = 7;
	dt->p_x = 23;
	dt->w_map = 28;
	dt->h_map = 9;
	return (dt);
}

t_game *init_map(void)
{
	t_game *gm = ft_calloc(1, sizeof(t_game));
	gm->maps.map = ft_calloc(10, sizeof(char *));
	gm->maps.map[0] = ft_strdup("1111111111111111111111111"); //fill the map
	gm->maps.map[1] = ft_strdup("1000000000000000000000001");
	gm->maps.map[2] = ft_strdup("10111111111000000000000011111111111111");
	gm->maps.map[3] = ft_strdup("101       1000000000000011111111111111");
	gm->maps.map[4] = ft_strdup("10111111111000000000000000000000000001");
	gm->maps.map[5] = ft_strdup("10000000000000000000000011111111111111");
	gm->maps.map[6] = ft_strdup("1000000000000000000000001");
	gm->maps.map[7] = ft_strdup("10000000000000000000000P1");
	gm->maps.map[8] = ft_strdup("1111111111111111111111111");
	gm->maps.map[9] = NULL;
	gm->maps.start_pos.y = 7;
	gm->maps.start_pos.x = 23;
	gm->maps.h_map = 9;
	gm->maps.w_map = 28;
	gm->floor_color = 0xB99470FF;
	gm->celling_color = 0x89CFF3FF;
	return (gm);
}

int main(void)
{
	// t_data	*data;
	t_game	*game;

	game = init_map();
	// data = init_argument();
	start_the_game(game);
	return (0);
}