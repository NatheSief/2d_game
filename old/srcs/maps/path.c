/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:47:10 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/17 18:41:10 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Permet de check si j'ai bien tous les collectibles et la sortie accessibles
// depuis mon joueur apres le passage de l'algo de dfs
int		check_info(t_count *new_map, t_count *map)
{
	if (new_map->collectibles != map->collectibles)
		return (0);
	if (new_map->exit != 1)
		return (0);
	if (new_map->wall > map->wall)
		return (0);
	return (1);
}

// Permet d'expand les appels de dfs sur les cases adjacentes a ma case de base
void	dfs_expand(t_map *map, int i, int j)
{
	map->map[i][j] = '1';
	dfs(map, i + 1, j);
	dfs(map, i - 1, j);
	dfs(map, i, j + 1);
	dfs(map, i, j - 1);
}

// Fonction de Depth-First Search, pour naviguer dans la map tout en 
// evitant tous les murs, me permet de recompter tous les collectibles,
// sortie en partant du player, et ainsi de verifier que j'ai bien acces a tout
// sans traverser les murs
void	dfs(t_map *map, int i, int j)
{
	if (i < 0 || i >= map->dimensions->width || j < 0 
		|| j >= map->dimensions->lenght)
		return;
	if (map->map[i][j] == 'W' || map->map[i][j] == '1')
		return;
	else if (map->map[i][j] == 'P')
	{
		map->info->player++;
		dfs_expand(map, i, j);
	}
	else if (map->map[i][j] == 'G')
	{
		dfs_expand(map, i, j);
	}
	else if(map->map[i][j] == 'C')
	{
		map->info->collectibles++;	
		dfs_expand(map, i, j);
	}
	else if (map->map[i][j] == 'E')
	{
		map->info->exit++;
		return ;
	}
}

// Permet de recuperer les coordonees de l'element envoye en parametre
void	get_point(t_map *map, t_point *elem, char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->dimensions->width)
	{
		j = 0;
		while (j < map->dimensions->lenght)
		{
			if (map->map[i][j] == c)
			{
				elem->x = i;
				elem->y = j;
				return ;
			}
			j++;
		}
		i++;
	}
	ft_error("L'element n'a pas ete trouve dans la map", map);
}

// Envoie des iterations continues pour checker le path entre tous les 
// collectibles et le joueur ainsi que l'exit et le joueur
void	check_path(t_map *map)
{
	t_map	*(new_map) = init_map();

	get_point(map, map->player, 'P');
	new_map->map = char_tab_dup(map, new_map);
	init_map_info(new_map->info);
	new_map->dimensions = map->dimensions;
	dfs(new_map, map->player->x, map->player->y);
	if (!check_info(new_map->info, map->info))
	{
		free(new_map);
		ft_error("Il n'y a pas de chemin valide", map);
	}
	free(new_map);
}
