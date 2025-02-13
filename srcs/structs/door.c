/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:52:37 by jbergos           #+#    #+#             */
/*   Updated: 2025/02/13 18:02:42 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_act_door	*init_act_door(void)
{
	t_act_door	*door;

	door = (t_act_door *) ft_calloc(1, sizeof(t_act_door));
	if (!door)
		return (NULL);
	return (door);
}

void	reset_act_door(t_act_door *door)
{
	door->close = 0;
	door->open = 0;
	door->close_h = 0;
	door->close_v = 0;
	door->open_h = 0;
	door->open_v = 0;
}

void	free_act_door(t_act_door *door)
{
	if (!door)
		return ;
	free(door);
}