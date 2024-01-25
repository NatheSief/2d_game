/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:44:29 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/25 12:27:12 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	dfs(t_game *game, int i, int j);

void	get_player_pos(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < LENGHT)
		{
			if (MAPS[i][j] == 'P')
			{
				MAP->info->player.x = i;
				MAP->info->player.y = j;
			}
		}
	}
}

int		check_info(t_game *game)
{
	if (MAP->info->info->c_collectibles != 0 || MAP->info->info->c_exit != 0
		|| MAP->info->info->c_player != 0)
		return (0);
	return (1);
}

// Permet d'expand les appels de dfs sur les cases adjacentes a ma case de base
void	dfs_expand(t_game *game, int i, int j)
{
	MAPS[i][j] += 32;
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
	if ((i < 0) || (i >= WIDTH) || (j < 0) 
		|| (j >= LENGHT))
		return;
	else if (MAPS[i][j] == 'W' || 
		(MAPS[i][j] >= 'a' && MAPS[i][j] <= 'z'))
		return;
	else if (MAPS[i][j] == 'P')
		MAP->info->info->c_player--;
	else if(MAPS[i][j] == 'C')
		MAP->info->info->c_collectibles--;	
	else if (MAPS[i][j] == 'E')
		MAP->info->info->c_exit--;
	dfs_expand(game, i, j);
}

// Envoie des iterations continues pour checker le path entre tous les 
// collectibles et le joueur ainsi que l'exit et le joueur
void	check_path(t_game *game)
{
	int	coll;
	int	exit;
	int	player;

	coll = MAP->info->info->c_collectibles;
	exit = MAP->info->info->c_exit;
	player = MAP->info->info->c_player;
	get_player_pos(game);
	dfs(game, MAP->info->player.x, MAP->info->player.y);
	if (!check_info(game))
		ft_error_free("There is no valid path in the map !", game);
	MAP->info->info->c_collectibles = coll;
	MAP->info->info->c_exit = exit;
	MAP->info->info->c_player = player;
	put_to_up(game);
}
