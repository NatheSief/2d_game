/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:12:54 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/23 17:06:08 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	affiche(t_game *game, t_texture *texture, int i, int j)
{
	mlx_put_image_to_window(MLX->mlx, MLX->win, texture, j * 64, i * 64);
}

static void affiche_map(t_game *game)
{
	int	i ;
	int	j ;
	
	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < LENGHT)
		{
			if (MAPS[i][j] == 'W')
				affiche(game, T_WALL, i, j);
			else if (MAPS[i][j] == 'G')
				affiche(game, T_GROUND, i, j);
			else if (MAPS[i][j] == 'C')
				affiche(game, T_COLL, i, j);
			else if (MAPS[i][j] == 'E')
				affiche(game, T_EXIT, i, j);
			else if (MAPS[i][j] == 'P')
				affiche(game, T_PLAYER, i, j);
		}
	}
}

// Permet de faire une action en fonction de la touche pressee
int	hook_repartor(int keycode, t_game *game)
{
	int	count;

	count = game->map->info->count_mouvements;
	if ((keycode == 'w' || keycode == 'a' || keycode == 's' || keycode == 'd' 
		|| keycode == 65307)) 
	{
		if (keycode == 'w') // W
			moveUp(game, game->map->info->player.x, game->map->info->player.y);
		else if (keycode == 'a') // A
			moveLeft(game, game->map->info->player.x, game->map->info->player.y);
		else if (keycode == 's') // S
			moveDown(game, game->map->info->player.x, game->map->info->player.y);
		else if (keycode == 'd') // D
			moveRight(game, game->map->info->player.x, game->map->info->player.y);
		else if (keycode == 65307) // Echap
			ft_error_free("Manual stop of the game :/ you're so bad ... !", game);
		if (count != game->map->info->count_mouvements)
		{
			ft_printf("\rCompteur de mouvement : %d", game->map->info->count_mouvements);
			evolve_display(game, game->map->info->player.x, game->map->info->player.y);
		}	
	}
	return (1);
}

void	launch_game(t_game *game)
{
	affiche_map(game);
	game->map->info->left_items = game->map->info->info->c_collectibles;
	game->map->info->count_mouvements = 0;
	mlx_hook(MLX->win, KeyPress, KeyPressMask, &hook_repartor, game);
	// mlx_hook(game->win, 33, )
	// mlx_mouse_hook();
	mlx_loop(game->mlx);
}
