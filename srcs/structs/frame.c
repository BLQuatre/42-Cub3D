/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:36:46 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/13 19:38:16 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_frame	*init_frame(void)
{
	t_frame	*frame;

	frame = (t_frame *) ft_calloc(1, sizeof(t_frame));
	if (!frame)
		return (NULL);
	return (frame);
}

void	free_frame(t_frame *frame)
{
	if (!frame)
		return ;
	if (frame->texture)
		mlx_delete_texture(frame->texture);
	free(frame);
	frame = NULL;
}
