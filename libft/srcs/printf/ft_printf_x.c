/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:08:26 by cauvray           #+#    #+#             */
/*   Updated: 2024/12/12 02:57:00 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"
#include "libft.h"

static long	ft_spaces_x(char *str, t_printf_params *params)
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
	if (params->hashtag && (result >= 2 || params->nb_before_dot
			- params->nb_after_dot < (int) ft_strlen(str) + 2
			|| (!params->dot && params->nb_before_dot
				< (int) ft_strlen(str) + 2)) && *str != '0')
		result -= 2;
	if (*str == '0' && params->dot && params->nb_after_dot == 0)
		result++;
	if (result > 0)
		return (result);
	return (0);
}

static	size_t	ft_putnstr_int0(char *str, int len, int remove_len)
{
	long long	value;

	value = len;
	return (ft_putnstr0(str, &value, remove_len));
}

size_t	ft_printf_x(t_printf_params *params, unsigned int n, int upper)
{
	size_t	size;
	long	spaces;
	char	*hex;

	size = 0;
	hex = ft_int_to_hex(n, upper);
	spaces = ft_spaces_x(hex, params);
	while (!params->minus && (!params->zero || params->dot) && spaces-- > 0)
		size += ft_putchar(' ');
	if (params->hashtag && n != 0)
		size += ft_putstr_case("0x", upper);
	if (params->zero && spaces > 0
		&& (!params->dot || params->nb_after_dot == 0
			|| params->nb_after_dot > params->nb_before_dot))
		size += ft_putnstr0(hex, (long long *) &spaces, 0);
	else if (params->dot && params->nb_after_dot > 0)
		size += ft_putnstr_int0(hex, params->nb_after_dot, 1);
	else if (n != 0 || (n == 0 && !params->dot))
		size += ft_putnstr0(hex, 0, 0);
	while (spaces-- > 0)
		size += ft_putchar(' ');
	free(hex);
	return (size);
}
