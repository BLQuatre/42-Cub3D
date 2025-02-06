/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:02:58 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/06 18:56:04 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	debug_show_vector(t_vector *vector)
{
	debug(GREEN, "VEC", "t_vector: (%p)", vector);
	if (!vector)
		return ;
	debug(GREEN, "VEC", "{");
	debug(GREEN, "VEC", "\tx: %d", vector->x);
	debug(GREEN, "VEC", "\ty: %d", vector->y);
	debug(GREEN, "VEC", "\th: %d", vector->h);
	debug(GREEN, "VEC", "}");
}
