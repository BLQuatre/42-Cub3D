/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:42:52 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/06 19:43:38 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	debug_get_color_str(uint32_t rgba, char buffer[27])
{
	sprintf(buffer, "RGBA: (%d, %d, %d, %d)", (rgba >> 24) & 0xFF,
		(rgba >> 16) & 0xFF, (rgba >> 8) & 0xFF, rgba & 0xFF);
}
