/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcleanjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 02:44:15 by cauvray           #+#    #+#             */
/*   Updated: 2024/12/12 02:50:39 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcleanjoin(char *s1, char *s2)
{
	char	*joined_str;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (s1);
	joined_str = ft_strjoin(s1, s2);
	free(s1);
	return (joined_str);
}
