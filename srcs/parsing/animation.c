/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:21:04 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/13 20:21:24 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void check_animations(t_game *game)
{
	int		i;
	char	*tmp_nbr;
	
	i = 0;
	while (i < ANIM_SIZE)
	{
		if (!game->animation->frames[i])
		{
			tmp_nbr = ft_itoa(i);
			add_error(game, ft_strjoin(INVALID_ANIM_TEXTURE,
				tmp_nbr));
			free(tmp_nbr);
		}
		i++;
	}
}

static void	load_animation(t_game *game, char *line, int i)
{
	char	*file;
	char	**split;
	
	split = ft_split(line, ' ');
	if (!split || array_len(split) != 2)
	{
		array_free(split);
		add_error(game, ft_strdup(INVALID_ANIM_FILE));
		return ;
	}
	game->animation->frames[i]->duration = ft_atoi(split[1]);
	file = ft_strjoin(ANIM_FOLDER, split[0]);
	game->animation->frames[i]->texture = mlx_load_png(file);
	free(file);
	if (!game->animation->frames[i]->texture)
		add_error(game, ft_strjoin(TEXTURE_LOAD_ERROR_MSG, split[0]));
	array_free(split);
}

void	load_animations(t_game *game)
{
	char	*line;
	int		anim_fd;
	int		i;

	line = ft_strjoin(ANIM_FOLDER, ANIM_FILE);
	anim_fd = open(line, O_RDONLY);
	free(line);
	if (!anim_fd)
		return (add_error(game, ft_strjoin(OPEN_READ_FILE_ERROR_MSG,
			ANIM_FILE)));
	line = get_next_line(anim_fd);
	i = 0;
	while (line && i < ANIM_SIZE)
	{
		load_animation(game, line, i);
		i++;
		free(line);
		line = get_next_line(anim_fd);
	}
	free(line);
	get_next_line(-1);
	close(anim_fd);
	check_animations(game);
	if (ft_lstsize(game->errors) > 0)
		quit(game, 1);
}
