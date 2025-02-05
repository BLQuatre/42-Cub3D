/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:20:13 by cauvray           #+#    #+#             */
/*   Updated: 2024/12/12 02:55:13 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/**
 * @brief Outputs a formatted string to stdout.
 *
 * This function sends a formatted output to the standard output (stdout),
 * using a format string str that can contain various format specifiers.
 * It can take a variable number of arguments, which are formatted
 * according to the provided format string.
 *
 * @param str The format string that specifies how subsequent arguments
 * are converted for output.
 * @param ... The variable number of arguments to format and output
 * according to the format string.
 * @return The total number of characters printed (excluding the null byte
 * used to end output to strings), or a negative number if an error occurs.
 *
 * @note Supported format specifiers include:
 * - %c: character
 * - %s: string
 * - %d: signed integer
 * - %u: unsigned integer
 * - %x: hexadecimal (lowercase)
 * - %X: hexadecimal (uppercase)
 * - %p: pointer
 * - %%%: prints a literal percent sign
 *
 * @warning If an unsupported format specifier is encountered,
 * behavior is undefined.
 */
int				ft_printf(const char *str, ...);

#endif