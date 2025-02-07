/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:50:59 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/07 20:37:07 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_data *init_argument(void)
{
	t_data	*dt = ft_calloc(1, sizeof(t_data));
	dt->map2d = ft_calloc(10, sizeof(char *));
	dt->map2d[0] = ft_strdup("1111111111111111111111111"); //fill the map
	dt->map2d[1] = ft_strdup("1000000000000000000100001");
	dt->map2d[2] = ft_strdup("1001000000000P00000000001");
	dt->map2d[3] = ft_strdup("1001000000000000001000001");
	dt->map2d[4] = ft_strdup("1001000000000000001000001");
	dt->map2d[5] = ft_strdup("1001000000100000001000001");
	dt->map2d[6] = ft_strdup("1001000000000000001000001");
	dt->map2d[7] = ft_strdup("1001000000001000001000001");
	dt->map2d[8] = ft_strdup("1111111111111111111111111");
	dt->map2d[9] = NULL;
	dt->p_y = 3;
	dt->p_y = 14;
	dt->w_map = 25;
	dt->h_map = 9;
	return (dt);
}

int main(void)
{
	t_data	*data;

	data = init_argument();
	start_the_game(data);
	return (0);
}