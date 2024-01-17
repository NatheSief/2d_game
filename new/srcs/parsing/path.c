/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:46:58 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/17 19:21:16 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	dfs(t_game *game, int i, int j);

int		check_info(t_game *new_game, t_game *game)
{
	if (new_game->info->count->count_coll != C_COLLECTIBLE)
		return (0);
	if (new_game->info->count->count_exit != 1)
		return (0);
	if (new_game->info->count->count_wall > COUNT->count_wall)
		return (0);
	return (1);
}

// Permet d'expand les appels de dfs sur les cases adjacentes a ma case de base
void	dfs_expand(t_game *game, int i, int j)
{
	MAPS->map[i][j] = '1';
	dfs(game, i + 1, j);
	dfs(game, i - 1, j);
	dfs(game, i, j + 1);
	dfs(game, i, j - 1);
}

// Fonction de Depth-First Search, pour naviguer dans la map tout en 
// evitant tous les murs, me permet de recompter tous les collectibles,
// sortie en partant du player, et ainsi de verifier que j'ai bien acces a tout
// sans traverser les murs
void	dfs(t_game *game, int i, int j)
{
	if (i < 0 || i >= WIDTH || j < 0 
		|| j >= LENGHT)
		return;
	if (MAPS->map[i][j] == 'W' || MAPS->map[i][j] == '1')
		return;
	else if (MAPS->map[i][j] == 'P')
	{
		C_PLAYER++;
		dfs_expand(game, i, j);
	}
	else if (MAPS->map[i][j] == 'G')
	{
		dfs_expand(game, i, j);
	}
	else if(MAPS->map[i][j] == 'C')
	{
		C_COLLECTIBLE++;	
		dfs_expand(game, i, j);
	}
	else if (MAPS->map[i][j] == 'E')
	{
		C_EXIT++;
		dfs_expand(game, i, j);
	}
}

// Envoie des iterations continues pour checker le path entre tous les 
// collectibles et le joueur ainsi que l'exit et le joueur
void	check_path(t_game *game)
{
	t_game	*new_game;
	
	new_game = game;
	dfs(new_game, PLAYER_P->x, PLAYER_P->y);
	if (!check_info(new_game, game))
	{
		empty_the_bin(new_game);
		ft_error_free("There is no valid path in the map !", game);
	}
	empty_the_bin(new_game);
}
