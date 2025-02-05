/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 04:26:45 by cauvray           #+#    #+#             */
/*   Updated: 2024/12/12 02:56:48 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"
#include "libft.h"

static void	ft_save_flag(t_printf_params **printf_params, char c)
{
	if (c == '-')
		(*printf_params)->minus = 1;
	else if (c == '0')
		(*printf_params)->zero = 1;
	else if (c == '.')
	{
		(*printf_params)->dot = 1;
		if ((*printf_params)->nb_before_dot == 0)
			(*printf_params)->zero = 1;
	}
	else if (c == '#')
		(*printf_params)->hashtag = 1;
	else if (c == ' ')
		(*printf_params)->space = 1;
	else if (c == '+')
		(*printf_params)->plus = 1;
	else if (ft_is_parsed_char(c))
		(*printf_params)->c = c;
}

char	*ft_get_printf_params_str(const char *str)
{
	int	i;

	i = 1;
	while (str[i] && ft_is_print_flag(str[i]))
		i++;
	if (!ft_is_parsed_char(str[i]))
		return (NULL);
	return (ft_substr(str, 0, i + 1));
}

t_printf_params	*ft_get_printf_params(char *str)
{
	t_printf_params	*params;

	params = (t_printf_params *) malloc(sizeof(t_printf_params));
	if (!params)
		return (NULL);
	ft_bzero(params, sizeof(t_printf_params));
	while (*str)
	{
		if (ft_isnum_no0(*str) && !(params->dot) && !(params->nb_before_dot))
		{
			params->nb_before_dot = ft_atoi(str);
			str += ft_nbrlen(params->nb_before_dot);
		}
		else if (ft_isdigit(*str) && params->dot && !(params->nb_after_dot))
		{
			params->nb_after_dot = ft_atoi(str);
			str += ft_nbrlen(params->nb_after_dot);
		}
		else
		{
			ft_save_flag(&params, *str);
			str++;
		}
	}
	return (params);
}
