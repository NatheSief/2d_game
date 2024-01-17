/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:10:45 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/17 19:18:12 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	garbage_init(t_game *game, void *ptr)
{
	t_garbage	trash;

	trash.content = ptr;
	trash.next = NULL;
	game->collector = trash;
	return (1);
}

int	malloc_garbage(t_game *game, void *ptr)
{
	t_garbage	trash;
	t_garbage	tmp;

	tmp = *TRASH;
	while (tmp.next)
		tmp = *tmp.next;
	trash.content = ptr;
	trash.next = NULL;
	tmp.next = &trash;
	return (1);
}

void	empty_the_bin(t_game *game)
{
	t_garbage tmp;

	tmp = *TRASH;
	while (tmp.next)
	{
		free(tmp.content);
		tmp = *tmp.next;
	}
	free(tmp.content);
	free(game);
	ft_printf("LES DECHETS CA VA DEHORS !!!");
}
