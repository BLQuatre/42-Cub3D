/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_id.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:21:01 by cauvray           #+#    #+#             */
/*   Updated: 2024/12/12 02:56:44 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"
#include "libft.h"

static long	ft_spaces_id(char *str, t_printf_params *params)
{
	long	result;

	result = 0;
	if (*str == '-' && params->zero && !params->dot
		&& params->nb_before_dot > params->nb_after_dot)
		return (params->nb_before_dot - ft_strlen(str));
	if (params->nb_before_dot <= params->nb_after_dot)
		return (0);
	result = params->nb_before_dot - ft_strlen(str);
	if (params->dot && params->nb_after_dot > (int) ft_strlen(str))
		result = params->nb_before_dot - params->nb_after_dot;
	if (((*str == '-' && params->dot && params->nb_before_dot
				> (int)ft_strlen(str) + params->nb_after_dot)
			|| params->plus || params->space || (*str == '-'
				&& params->nb_before_dot > params->nb_after_dot)
		) && (((int)ft_strlen(str) - 1 < params->nb_after_dot) || *str != '-')
	)
		result--;
	if (*str == '0' && params->dot && params->nb_after_dot == 0)
		result++;
	if (result > 0)
		return (result);
	return (0);
}

size_t	ft_printf_id(t_printf_params *params, int n)
{
	size_t	size;
	long	spaces;
	char	*nbr;

	size = 0;
	nbr = ft_itoa(n);
	spaces = ft_spaces_id(nbr, params);
	while (!params->minus && (!params->zero || params->dot) && spaces-- > 0)
		size += ft_putchar(' ');
	if (params->space && n >= 0)
		size += ft_putchar(' ');
	else if (params->plus && n >= 0)
		size += ft_putchar('+');
	if (params->zero && spaces > 0
		&& (!params->dot || params->nb_after_dot == 0))
		size += ft_putnstr0(nbr, (long long *) &spaces, 0);
	else if (params->dot && params->nb_after_dot > 0)
		size += ft_putnstr0(nbr, (long long *) &(params->nb_after_dot), 1);
	else if (n != 0 || (n == 0 && !params->dot))
		size += ft_putnstr0(nbr, 0, 0);
	while (spaces-- > 0)
		size += ft_putchar(' ');
	free(nbr);
	return (size);
}
