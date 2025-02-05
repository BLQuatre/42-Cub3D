/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_param.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 08:37:11 by cauvray           #+#    #+#             */
/*   Updated: 2024/11/29 08:45:40 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter_param(t_list *lst, void (*f)(void *, void *), void *ptr)
{
	while (lst)
	{
		f(lst->content, ptr);
		lst = lst->next;
	}
}
