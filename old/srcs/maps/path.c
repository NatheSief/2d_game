/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:44:29 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/21 13:47:41 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	get_player_pos(t_map *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->dimensions->width)
	{
		j = -1;
		while (++j < game->dimensions->lenght)
		{
			if (game->map[i][j] == 'P')
			{
				game->player->x = i;
				game->player->y = j;
			}
		}
	}
}

int		check_info(t_map *game)
{
	if (game->info->collectibles != 0 || game->info->exit != 0
		|| game->info->player != 0)
		return (0);
	return (1);
}

// Permet d'expand les appels de dfs sur les cases adjacentes a ma case de base
void	dfs_expand(t_map *game, int i, int j)
{
	game->map[i][j] += 32;
	dfs(game, i + 1, j);
	dfs(game, i - 1, j);
	dfs(game, i, j + 1);
	dfs(game, i, j - 1);
}

// Fonction de Depth-First Search, pour naviguer dans la map tout en 
// evitant tous les murs, me permet de recompter tous les collectibles,
// sortie en partant du player, et ainsi de verifier que j'ai bien acces a tout
// sans traverser les murs
void	dfs(t_map *game, int i, int j)
{
	if ((i < 0) || (i >= game->dimensions->width) || (j < 0) 
		|| (j >= game->dimensions->lenght))
		return;
	else if (game->map[i][j] == 'W' || 
		(game->map[i][j] >= 'a' && game->map[i][j] <= 'z'))
		return;
	else if (game->map[i][j] == 'P')
		game->info->player--;
	else if(game->map[i][j] == 'C')
		game->info->collectibles--;	
	else if (game->map[i][j] == 'E')
		game->info->exit--;
	dfs_expand(game, i, j);
}

// Envoie des iterations continues pour checker le path entre tous les 
// collectibles et le joueur ainsi que l'exit et le joueur
void	check_path(t_map *game)
{
	int	coll;
	int	exit;
	int	player;

	coll = game->info->collectibles;
	exit = game->info->exit;
	player = game->info->player;
	get_player_pos(game);
	dfs(game, game->player->x, game->player->y);
	if (!check_info(game))
		ft_error("There is no valid path in the map !", game);
	game->info->collectibles = coll;
	game->info->exit = exit;
	game->info->player = player;
	put_to_up(game);
}
