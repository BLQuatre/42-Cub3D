/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:36:46 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/13 05:54:53 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_textures	*init_textures(void)
{
	t_textures	*textures;

	textures = (t_textures *) ft_calloc(1, sizeof(t_textures));
	if (!textures)
		return (NULL);
	return (textures);
}

void	free_textures(t_textures *textures)
{
	if (!textures)
		return ;
	if (textures->north)
		mlx_delete_texture(textures->north);
	if (textures->south)
		mlx_delete_texture(textures->south);
	if (textures->west)
		mlx_delete_texture(textures->west);
	if (textures->east)
		mlx_delete_texture(textures->east);
	if (textures->door)
		mlx_delete_texture(textures->door);
	free(textures->floor);
	textures->floor = NULL;
	free(textures->celling);
	textures->celling = NULL;
	free(textures);
	textures = NULL;
}
