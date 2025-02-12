/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:32:15 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/12 01:32:25 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_valid_extension(char *file, char *extension)
{
	char	*found_ext;

	found_ext = ft_strrchr(file, '.');
	if (!found_ext)
		return (false);
	return (ft_strncmp(found_ext, extension, ft_strlen(extension) + 1) == 0);
}
