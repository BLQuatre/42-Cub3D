/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:29:27 by cauvray           #+#    #+#             */
/*   Updated: 2024/11/02 21:36:00 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

/**
 * @brief Reads a line from a file descriptor.
 *
 * This function reads from the given file descriptor until a newline character
 * is encountered or the end of the file is reached. It allocates memory for
 * the line read and returns a pointer to it. The caller is responsible for
 * freeing the memory when it is no longer needed.
 *
 * @param fd The file descriptor to read from.
 * It must be a valid open file descriptor.
 * @return A pointer to the line read from the file descriptor,
 * or NULL if an error occurs
 * or if there are no more lines to read (end of file).
 *
 * @note If the end of the file is reached without reading any characters,
 * the function returns NULL.
 */
char	*get_next_line(int fd);

#endif