/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:33:58 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/12 01:34:45 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_error(t_list **lst, char *msg)
{
	t_list	*new;

	new = ft_lstnew(msg);
	if (!new)
		return ;
	ft_lstadd_back(lst, new);
}

void	show_errors(t_list **errors)
{
	t_list	*tmp;

	if (!errors)
		return ;
	tmp = *errors;
	ft_putendl_fd("Error", 2);
	ft_putstr_fd("\e[31m", 2);
	while (tmp)
	{
		ft_putendl_fd(tmp->content, 2);
		tmp = tmp->next;
	}
	ft_putstr_fd("\e[0m", 2);
	ft_lstclear(errors, free);
	errors = NULL;
}

void	quit(t_game *game, int exit_code)
{
	if (exit_code > 0)
	{
		if (ft_lstsize(game->errors) == 0)
			add_error(&game->errors, ft_strdup(INVALID_MAP_MSG));
		show_errors(&game->errors);
	}
	free_game(game);
	exit(exit_code);
}
