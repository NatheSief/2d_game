/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:15:20 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/25 13:28:11 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Check si je n'ai qu'une sortie et player + si je n'ai que des elements
// connus dans la map
static void	check_map_info(t_game *game)
{
	int	elems;

	elems = 0;
	
	if (MAP->info->info->c_exit != 1)
	{
		if (MAP->info->info->c_exit == 0)
			ft_error_free("La map doit avoir une sortie", game);
		else if (MAP->info->info->c_exit > 1)
			ft_error_free("La map doit avoir une seule sortie", game);
	}
	else if (MAP->info->info->c_player != 1)
		ft_error_free("La map doit avoir un seul joueur", game);
	else if (MAP->info->info->c_collectibles == 0)
		ft_error_free("La map doit avoir au moins un collectible", game);
}

// Verifier les walls
static void	check_parse(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++j < LENGHT - 1)
	{
		if (MAPS[0][j] != 'W' || MAPS[WIDTH - 1][j] != 'W')
			ft_error_free("Maps isn't surrounded by walls on top", game);
	}
	while (++i < WIDTH - 1)
	{
		if (MAPS[i][0] != 'W' || MAPS[i][LENGHT - 2] != 'W')
			ft_error_free("Maps isn't surrounded by walls on sides", game);
	}
	check_map_info(game);
}

// Verifie toutes les informations de ma map et les enregistre dans les champs
// dedies dans les structures.
void	check_map(t_game *game)
{
	check_parse(game);
	check_path(game);
}
