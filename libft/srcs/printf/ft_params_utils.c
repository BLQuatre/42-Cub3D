/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 01:14:10 by cauvray           #+#    #+#             */
/*   Updated: 2024/12/12 02:56:27 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"
#include "libft.h"

int	ft_is_parsed_char(char c)
{
	char	*str;

	str = "cspdiuxX%";
	while (*str)
	{
		if (c == *str++)
			return (1);
	}
	return (0);
}

int	ft_is_print_flag(char c)
{
	char	*str;

	str = "-0.# +";
	while (*str)
	{
		if (ft_isdigit(c) || c == *str++)
			return (1);
	}
	return (0);
}

int	ft_isnum_no0(char c)
{
	return (c >= '1' && c <= '9');
}
