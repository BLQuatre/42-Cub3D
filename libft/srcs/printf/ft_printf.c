/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:05:40 by cauvray           #+#    #+#             */
/*   Updated: 2024/12/12 02:57:03 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"
#include "libft.h"

static int	ft_free_params(t_printf_params *params)
{
	free(params);
	return (0);
}

static size_t	ft_formats(va_list args, char *params_str)
{
	t_printf_params	*params;
	size_t			size;

	params = ft_get_printf_params(params_str);
	if (!params)
		return (ft_free_params(params));
	size = 0;
	if (params->c == 'c')
		size += ft_printf_c(params, va_arg(args, int));
	else if (params->c == 's')
		size += ft_printf_s(params, va_arg(args, char *));
	else if (params->c == 'p')
		size += ft_printf_p(params, (void *) va_arg(args, void *));
	else if (params->c == 'd' || params->c == 'i')
		size += ft_printf_id(params, va_arg(args, int));
	else if (params->c == 'u')
		size += ft_printf_u(params, va_arg(args, unsigned int));
	else if (params->c == 'x')
		size += ft_printf_x(params, va_arg(args, unsigned int), 0);
	else if (params->c == 'X')
		size += ft_printf_x(params, va_arg(args, unsigned int), 1);
	else if (params->c == '%')
		size += ft_putchar('%');
	free(params);
	return (size);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;
	char	*params_str;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			params_str = ft_get_printf_params_str(str + i);
			if (params_str)
			{
				print_length += ft_formats(args, params_str);
				i += ft_strlen(params_str);
			}
			free(params_str);
		}
		else
			print_length += ft_putchar(str[i++]);
	}
	va_end(args);
	return (print_length);
}
