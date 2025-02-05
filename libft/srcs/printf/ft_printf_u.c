/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:08:26 by cauvray           #+#    #+#             */
/*   Updated: 2024/12/12 02:56:55 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"
#include "libft.h"

static long long	ft_spaces_u(char *str, t_printf_params *params)
{
	long long	result;

	result = 0;
	if (params->zero && !params->dot
		&& params->nb_before_dot > params->nb_after_dot)
		return (params->nb_before_dot - ft_strlen(str));
	if (params->nb_before_dot <= params->nb_after_dot)
		return (0);
	result = params->nb_before_dot - ft_strlen(str);
	if (params->dot && params->nb_after_dot > (int) ft_strlen(str))
		result = params->nb_before_dot - params->nb_after_dot;
	if (*str == '0' && params->dot && params->nb_after_dot == 0)
		result++;
	if (result > 0)
		return (result);
	return (0);
}

size_t	ft_printf_u(t_printf_params *params, unsigned int n)
{
	size_t			size;
	long long		spaces;
	char			*nbr;

	size = 0;
	nbr = ft_uitoa(n);
	spaces = ft_spaces_u(nbr, params);
	while (!params->minus && (!params->zero || params->dot) && spaces-- > 0)
		size += ft_putchar(' ');
	if (params->zero && spaces > 0
		&& (!params->dot || params->nb_after_dot == 0
			|| params->nb_after_dot > params->nb_before_dot))
		size += ft_putnstr0(nbr, &spaces, 0);
	else if (params->dot && params->nb_after_dot > 0)
		size += ft_putnstr0(nbr, (long long *) &(params->nb_after_dot), 1);
	else if (n != 0 || (n == 0 && !params->dot))
		size += ft_putnstr0(nbr, 0, 0);
	while (spaces-- > 0)
		size += ft_putchar(' ');
	free(nbr);
	return (size);
}
