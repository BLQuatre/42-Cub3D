/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:43:54 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/12 15:44:04 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	remove_end_newline(char *line)
{
	int	newline_i;

	if (!line || !line[0])
		return ;
	newline_i = ft_strlen(line) - 1;
	if (line[newline_i] == '\n')
		line[newline_i] = '\0';
}
