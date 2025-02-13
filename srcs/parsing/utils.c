/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:47:35 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/12 20:24:59 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

bool	is_map_char(char c)
{
	int	i;

	i = ft_strlen(MAP_CHARS) - 1;
	while (i >= 0)
	{
		if (MAP_CHARS[i] == c)
			return (true);
		i--;
	}
	return (false);
}

int	remove_end_newline_and_spaces(char *str)
{
	int		i;
	int		count;

	if (!str || !str[0])
		return (0);
	i = ft_strlen(str) - 1;
	if (i >= 0 && str[i] == '\n')
	{
		str[i] = '\0';
		i--;
	}
	count = 0;
	while (i >= 0 && str[i] == ' ')
	{
		str[i] = '\0';
		count++;
		i--;
	}
	if (ft_strlen(str) > 0)
		return (0);
	return (count);
}

bool	is_valid_extension(char *file, char *extension)
{
	char	*found_ext;

	found_ext = ft_strrchr(file, '.');
	if (!found_ext)
		return (false);
	return (ft_strncmp(found_ext, extension, ft_strlen(extension) + 1) == 0);
}

char	**map_list_to_map_array(t_list *lst)
{
	char	**map_array;
	t_list	*tmp;
	int		i;
	int		j;

	i = 0;
	tmp = lst;
	while (tmp && tmp->content && ft_strlen(tmp->content) > 0)
	{
		i++;
		tmp = tmp->next;
	}
	j = 0;
	map_array = (char **) ft_calloc(i + 1, sizeof(char *));
	if (!map_array)
		return (NULL);
	while (lst && j < i)
	{
		map_array[j] = ft_strdup(lst->content);
		j++;
		lst = lst->next;
	}
	map_array[j] = NULL;
	return (map_array);
}
