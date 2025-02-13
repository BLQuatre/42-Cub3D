/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:36:46 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/13 19:36:22 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_animation	*init_animation(void)
{
	t_animation	*animation;
	int			i;

	animation = (t_animation *) ft_calloc(1, sizeof(t_animation));
	if (!animation)
		return (NULL);
	i = 0;
	while (i < ANIM_SIZE)
	{
		animation->frames[i] = init_frame();
		i++;
	}
	animation->frames[i] = NULL;
	return (animation);
}

void	free_animation(t_animation *animation)
{
	int	i;

	if (!animation)
		return ;
	i = 0;
	while (animation->frames[i])
	{
		free_frame(animation->frames[i]);
		animation->frames[i] = NULL;
		i++;
	}
	free(animation);
	animation = NULL;
}
