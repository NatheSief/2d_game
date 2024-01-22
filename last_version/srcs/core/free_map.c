/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:06:00 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/22 15:37:27 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// static void	free_infos(t_game *game)
// {

// }

// Free toutes les lignes de mon tableau de strings
void libere(char **elem)
{
	int i;

	if (elem)
	{
		i = 0;
		while (elem[i])
		{
			free(elem[i]);
			i++;
		}
		free(elem);
	}
}

// Free ma structure map
void	ft_free_map(t_game *game)
{
	if (game->map->info)
		free(game->map->info);
	if (MAP)
		libere(game);
	if (game->map->name)
		free(game->map->name);
	free(game->map);
}