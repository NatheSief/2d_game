/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:12:54 by nsiefert          #+#    #+#             */
/*   Updated: 2024/02/01 08:53:44 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	affiche(t_game *game, t_texture *texture, int wid, int len)
{
	mlx_put_image_to_window(MLX->mlx, MLX->win, texture, len * 64, wid * 64);
}

static void	affiche_map(t_game *game)
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
		if (keycode == 'w')
			move_up(game, PLAYER.x, PLAYER.y);
		else if (keycode == 'a')
			move_left(game, PLAYER.x, PLAYER.y);
		else if (keycode == 's')
			move_down(game, PLAYER.x, PLAYER.y);
		else if (keycode == 'd')
			move_right(game, PLAYER.x, PLAYER.y);
		else if (keycode == 65307)
			ft_end_game("\nManual stop of the game :/\n", game);
		if (count != game->map->info->count_mouvements)
		{
			ft_printf("\r Moves : %d", game->map->info->count_mouvements);
			evolve_display(game, PLAYER.y, PLAYER.x);
		}	
	}
	return (1);
}

int	red_cross(t_game *game)
{
	ft_printf("\nManual stop of the game via red cross press ! \n");
	ft_free_struct(game);
	exit(1);
}

void	launch_game(t_game *game)
{
	affiche_map(game);
	game->map->info->left_items = game->map->info->info->c_collectibles;
	game->map->info->count_mouvements = 0;
	mlx_hook(MLX->win, KeyPress, KeyPressMask, &hook_repartor, game);
	mlx_hook(MLX->win, DestroyNotify, NoEventMask, &red_cross, game);
	mlx_loop(game->mlx->mlx);
}
