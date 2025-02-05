/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:21:05 by cauvray           #+#    #+#             */
/*   Updated: 2024/12/12 02:57:13 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"
#include "libft.h"

size_t	ft_unbrlen(unsigned int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	size_t	n_size;
	char	*str;

	n_size = ft_unbrlen(n);
	str = (char *) malloc(sizeof(char) * (n_size + 1));
	if (!str)
		return (NULL);
	str[n_size] = 0;
	while (n_size-- > 0)
	{
		str[n_size] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

int	ft_putnstr0(char *str, long long *len, int remove_len)
{
	int	count;

	count = 0;
	if (*str == '-')
		count += ft_putchar(*str++);
	if (len && remove_len)
		*len -= ft_strlen(str);
	while (len && (*len)-- > 0)
		count += ft_putchar('0');
	while (*str)
		count += ft_putchar(*str++);
	return (count);
}
