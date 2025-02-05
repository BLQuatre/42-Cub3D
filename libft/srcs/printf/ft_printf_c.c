/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:08:26 by cauvray           #+#    #+#             */
/*   Updated: 2024/12/12 02:56:12 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"
#include "libft.h"

static int	ft_spaces_c(int nb_bef)
{
	if (nb_bef > 0)
		return (nb_bef - 1);
	else
		return (0);
}

size_t	ft_printf_c(t_printf_params *params, char c)
{
	size_t	size;
	int		spaces;

	size = 0;
	spaces = ft_spaces_c(params->nb_before_dot);
	while (!params->minus && spaces-- > 0)
		size += ft_putchar(' ');
	size += ft_putchar(c);
	while (spaces-- > 0)
		size += ft_putchar(' ');
	return (size);
}
