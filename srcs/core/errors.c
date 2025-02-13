/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:33:58 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/13 05:37:59 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_error(char *line)
{
	ft_putendl_fd(line, 2);
}

void	add_error(t_game *game, char *msg)
{
	t_list	*new;

	new = ft_lstnew(msg);
	if (!new)
		return ;
	ft_lstadd_back(&game->errors, new);
}

void	show_errors(t_game *game)
{
	if (!game->errors)
		return ;
	ft_putendl_fd("Error", 2);
	ft_putstr_fd("\e[31m", 2);
	ft_lstiter(game->errors, (void (*)(void *)) print_error);
	ft_putstr_fd("\e[0m", 2);
	ft_lstclear(&game->errors, free);
	game->errors = NULL;
}

void	quit(t_game *game, int exit_code)
{
	if (exit_code > 0)
	{
		if (ft_lstsize(game->errors) == 0)
			add_error(game, ft_strdup(INVALID_MAP_MSG));
		show_errors(game);
	}
	free_game(game);
	exit(exit_code);
}
