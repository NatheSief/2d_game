/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:46:58 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/19 16:25:49 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int		check_info(t_game *game)
{
	if (C_COLLECTIBLE != 0 || C_EXIT != 0)
		return (0);
	return (1);
}

// Permet d'expand les appels de dfs sur les cases adjacentes a ma case de base
void	dfs_expand(t_game *game, int i, int j)
{
	MAPS->map[i][j] -= 32;
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
	if ((i < 0) || (i >= WIDTH) || (j < 0) || (j >= LENGHT))
		return;
	else if (MAPS->map[i][j] == 'W' || 
		(MAPS->map[i][j] >= 'a' && MAPS->map[i][j] <= 'z'))
		return;
	else if (MAPS->map[i][j] == 'P')
		C_PLAYER--;
	else if(MAPS->map[i][j] == 'C')
		C_COLLECTIBLE--;	
	else if (MAPS->map[i][j] == 'E')
		C_EXIT--;
	dfs_expand(game, i, j);
}

// Envoie des iterations continues pour checker le path entre tous les 
// collectibles et le joueur ainsi que l'exit et le joueur
void	check_path(t_game *game)
{
	t_count	infos;

	infos.count_coll = C_COLLECTIBLE;
	infos.count_exit = C_EXIT;
	infos.count_ground = C_GROUND;
	infos.count_player = C_PLAYER;
	infos.count_wall = C_WALL;
	dfs(game, PLAYER_P->x, PLAYER_P->y);
	if (!check_info(game))
		ft_error_free("There is no valid path in the map !", game);
	C_COLLECTIBLE = infos.count_coll;
	C_EXIT = infos.count_exit;
	C_GROUND = infos.count_ground;
	C_PLAYER = infos.count_player;
	C_WALL = infos.count_wall;
	put_to_up(game);
}
