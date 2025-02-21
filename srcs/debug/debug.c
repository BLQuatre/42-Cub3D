/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:39:50 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/17 15:53:13 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

const char	*g_colors[] = {
	"\033[30m",
	"\033[31m",
	"\033[32m",
	"\033[33m",
	"\033[34m",
	"\033[35m",
	"\033[36m",
	"\033[37m",
	"\033[90m",
	"\033[91m",
	"\033[92m",
	"\033[93m",
	"\033[94m",
	"\033[95m",
	"\033[96m",
	"\033[97m"
};

void	debug(t_debug_color color, const char *tag, const char *format, ...)
{
	char	buffer[1024];
	va_list	args;

	va_start(args, format);
	vsnprintf(buffer, sizeof(buffer), format, args);
	dprintf(2, "%s[DEBUG / %5.5s] \033[0m%s\n", g_colors[color], tag, buffer);
	va_end(args);
}
