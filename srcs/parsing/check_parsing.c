/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:41:23 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/15 17:01:12 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Regarde si la ligne du haut et celle du bas sont remplies de murs
void	check_top_bottom(t_map *map)
{
	int	j;

	j = 0;
	while (j < map->dimensions->lenght - 1)
	{		
		if (map->map[0][j] != 'W')
			ft_error("La map n'est pas entouree de murs en haut", map);
		else if (map->map[map->dimensions->width - 1][j] != 'W')
			ft_error("La map n'est pas entouree de murs en bas la en bas", map);
		j++;
	}
}

// Regarde si les colonnes exterieures sont bien que des murs
void check_sides(t_map *map)
{
	int i;

	i = 1;
	while (i < map->dimensions->width - 2)
	{
		if (map->map[i][0] != 'W' || map->map[i][map->dimensions->lenght - 1] != 'W')
			ft_error("La map n'est pas entouree de murs sur un cote", map);
		i++;
	}
}

// Comptes les differents elements de la map
void	count_elems(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->dimensions->width)
	{
		j = 0;
		while (j < map->dimensions->lenght)
		{
			if (map->map[i][j] == 'E')
				map->info->exit ++;
			else if (map->map[i][j] == 'P')
				map->info->player ++;
			else if (map->map[i][j] == 'C')
				map->info->collectibles ++;
			else if (map->map[i][j] == 'W')
				map->info->wall ++;
			else if (map->map[i][j] == 'G')
				map->info->ground ++;
			j++;
		}
		i++;
	}
	check_map_info(map);
}

// Regarde si la map est entouree de murs et check le nombres d'elements
// Dans la map apres avoir regarde pour les murs
void	check_parse(t_map *map)
{
	map->info = malloc(sizeof (t_count));
	init_map_info(map->info);
	check_top_bottom(map);
	check_sides(map);
	count_elems(map);
	check_path(map);
}
