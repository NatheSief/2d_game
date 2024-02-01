/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:06:00 by nsiefert          #+#    #+#             */
/*   Updated: 2024/02/01 12:28:36 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Free toutes les lignes de mon tableau de strings
void	libere(char **elem)
{
	int	i;

	if (elem)
	{
		i = 0;
		while (elem[i])
		{
			free(elem[i]);
			i++;
		}
		free(elem[i]);
		free(elem);
	}
}

// Free ma structure map
void	ft_free_map(t_game *game)
{
	if (game->map->info)
	{
		if (game->map->info->dimensions)
			free(game->map->info->dimensions);
		if (game->map->info->info)
			free(game->map->info->info);
		free(game->map->info);
	}
	if (game->map->map)
		libere(game->map->map);
	if (game->map->name)
		free(game->map->name);
	free(game->map);
}
