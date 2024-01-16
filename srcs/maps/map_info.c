/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:36:34 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/16 10:10:12 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Met tous les elements de t_count a 0
void	init_map_info(t_count *map_info)
{
	map_info->exit = 0;
	map_info->player = 0;
	map_info->collectibles = 0;
	map_info->wall = 0;
	map_info->ground = 0;
}

// Check si je n'ai qu'une sortie et player + si je n'ai que des elements
// connus dans la map
void	check_map_info(t_map *map)
{
	int	elems;

	elems = 0;
	
	if (map->info->exit != 1)
	{
		if (map->info->exit == 0)
			ft_error("La map doit avoir une sortie", map);
		else if (map->info->exit > 1)
			ft_error("La map doit avoir une seule sortie", map);
	}
	else if (map->info->player != 1)
		ft_error("La map doit avoir un seul joueur", map);
	else if (map->info->collectibles == 0)
		ft_error("La map doit avoir au moins un collectible", map);
	elems = map->info->collectibles + map->info->ground + map->info->wall + 2;
	if (elems != ((map->dimensions->width) * (map->dimensions->lenght)))
		ft_error("La map ne doit contenir que des elements connus", map);
}

// void	get_map_name(t_map	*map, char )