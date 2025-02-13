/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:25:58 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/13 19:35:08 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_color(char *raw_str_num)
{
	char	*str_num;
	int		num;

	str_num = ft_strtrim(raw_str_num, " ");
	if (!str_num || ft_strlen(str_num) == 0 || ft_strlen(str_num) > 3)
		return (free(str_num), -1);
	num = ft_atoi(str_num);
	free(str_num);
	if (num < 0 || num > 255)
		return (-1);
	return (num);
}

t_color	*handle_color(char *str_color)
{
	char	**colors;
	int		rgb[3];

	colors = ft_split(str_color, ',');
	if (!colors || array_len(colors) != 3)
		return (array_free(colors), NULL);
	rgb[0] = get_color(colors[0]);
	rgb[1] = get_color(colors[1]);
	rgb[2] = get_color(colors[2]);
	array_free(colors);
	if (rgb[0] == -1 || rgb[1] == -1 || rgb[2] == -1)
		return (NULL);
	return (uint_to_t_color(rgba_to_uint(rgb[0], rgb[1], rgb[2], 255)));
}
