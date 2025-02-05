/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:31:23 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/15 22:58:05 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charcmp(char c1, char c2)
{
	if ((unsigned char) c1 != (unsigned char) c2)
		return ((unsigned char) c1 - (unsigned char) c2);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (ft_charcmp(s1[i], s2[i]))
			return (ft_charcmp(s1[i], s2[i]));
		i++;
	}
	if (i < n)
		return (ft_charcmp(s1[i], s2[i]));
	return (0);
}
