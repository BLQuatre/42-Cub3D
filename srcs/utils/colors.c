/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:36:49 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/10 13:33:11 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color	*uint_to_t_color(const uint32_t rgba)
{
	t_color	*color;

	color = (t_color *) ft_calloc(1, sizeof(t_color));
	color->r = (rgba >> 24) & 0xFF;
	color->g = (rgba >> 16) & 0xFF;
	color->b = (rgba >> 8) & 0xFF;
	color->a = rgba & 0xFF;
	return (color);
}

uint32_t	t_color_to_uint(const t_color *color)
{
	if (!color)
		return (0);
	return (((uint32_t) color->r << 24)
		| ((uint32_t) color->g << 16)
		| ((uint32_t) color->b << 8)
		| ((uint32_t) color->a));
}
