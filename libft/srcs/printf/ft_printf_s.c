/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:08:26 by cauvray           #+#    #+#             */
/*   Updated: 2024/12/12 02:56:50 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"
#include "libft.h"

static int	ft_spaces_s(char *str, t_printf_params *params)
{
	int	str_len;

	str_len = ft_strlen(str);
	if (str_len > params->nb_after_dot && params->nb_after_dot > 0)
		str_len = params->nb_after_dot;
	if (params->nb_before_dot >= str_len
		&& (!params->dot || params->nb_after_dot > 0))
		return (params->nb_before_dot - str_len);
	if ((params->nb_before_dot > str_len && params->nb_before_dot > 0)
		|| (params->dot && params->nb_after_dot == 0))
		return (params->nb_before_dot);
	return (0);
}

static size_t	ft_putnstr(char *str, size_t len)
{
	size_t	count;

	count = 0;
	while (str[count] && count < len)
		ft_putchar(str[count++]);
	return (count);
}

size_t	ft_printf_s(t_printf_params *params, char *str)
{
	size_t	size;
	int		spaces;

	size = 0;
	if (!str && (!params->dot || params->nb_after_dot > 5))
		str = "(null)";
	else if (!str)
		str = "";
	spaces = ft_spaces_s(str, params);
	while (!params->minus && spaces-- > 0)
		size += ft_putchar(' ');
	if (params->dot)
		size += ft_putnstr(str, params->nb_after_dot);
	else
		size += ft_putstr(str);
	while (spaces-- > 0)
		size += ft_putchar(' ');
	return (size);
}
