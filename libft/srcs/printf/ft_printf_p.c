/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:21:17 by cauvray           #+#    #+#             */
/*   Updated: 2024/12/12 02:56:46 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"
#include "libft.h"

static long long	ft_spaces_p(char *str, t_printf_params *params)
{
	long long	result;
	size_t		len;

	if (*str == '(')
		len = ft_strlen(str);
	else
		len = ft_strlen(str) + 2;
	result = 0;
	if (params->dot && params->nb_after_dot == 0
		&& (ft_strncmp(str, "(nil)", 6) && *str != '0'))
		return (0);
	if (params->nb_before_dot > (int)len)
		result = params->nb_before_dot - len;
	if (params->dot && params->nb_after_dot > (int)len)
		result = params->nb_before_dot - params->nb_after_dot;
	if (*str == '0' && params->dot && params->nb_after_dot == 0)
		result++;
	if (result < 0)
		return (0);
	return (result);
}

size_t	ft_printf_p(t_printf_params *params, void *ptr)
{
	size_t			size;
	long long		spaces;
	char			*hex_str;

	size = 0;
	if ((unsigned long long) ptr == 0)
		hex_str = ft_strdup("(nil)");
	else
		hex_str = ft_ptr_to_hex((unsigned long long) ptr);
	spaces = ft_spaces_p(hex_str, params);
	while (!params->minus && (!params->zero || params->dot) && spaces-- > 0)
		size += ft_putchar(' ');
	if ((unsigned long long) ptr != 0)
		size += ft_putstr("0x");
	if (params->zero && spaces > 0 && (!params->dot || params->nb_after_dot
			== 0 || params->nb_after_dot > params->nb_before_dot))
		size += ft_putnstr0(hex_str, &spaces, 0);
	else if (params->dot && params->nb_after_dot > 0)
		size += ft_putnstr0(hex_str, (long long *)&(params->nb_after_dot), 1);
	else if (ptr != NULL || (ptr == NULL && !params->dot))
		size += ft_putnstr0(hex_str, 0, 0);
	while (spaces-- > 0)
		size += ft_putchar(' ');
	free(hex_str);
	return (size);
}
