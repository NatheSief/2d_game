/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:36:34 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/10 10:25:35 by nsiefert         ###   ########.fr       */
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
void	check_map_info(t_count *map_info, char **map, int lines, int culumns)
{
	int	elems;

	elems = 0;
	if (map_info->exit != 1)
	{
		free(map_info);
		ft_error("La map doit avoir une seule sortie", map);
	}
	if (map_info->player != 1)
	{
		free(map_info);
		ft_error("La map doit avoir un seul joueur", map);
	}
	elems = map_info->collectibles + map_info->ground + map_info->wall + 2;
	if (elems != lines * culumns)
	{
		free(map_info);
		ft_error("La map ne doit contenir que des elements connus", map);
	}
}
