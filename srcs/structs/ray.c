/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:36:46 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/13 06:00:27 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ray	*init_ray(void)
{
	t_ray	*ray;

	ray = (t_ray *) ft_calloc(1, sizeof(t_ray));
	if (!ray)
		return (NULL);
	return (ray);
}

void	free_ray(t_ray *ray)
{
	if (!ray)
		return ;
	free(ray);
	ray = NULL;
}
