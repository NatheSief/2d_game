/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:12:54 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/23 15:34:54 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	charge_textures(t_mlx *game)
{
	int	width;
	int	length;

	width = RES;
	length = RES;
	// check_open(game);
	game->map->t_collectible = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE_PATH, &width, &length);
	game->map->t_exit = mlx_xpm_file_to_image(game->mlx, EXIT_PATH, &width, &length);
	game->map->t_ground = mlx_xpm_file_to_image(game->mlx, GROUND_PATH, &width, &length);
	game->map->t_player = mlx_xpm_file_to_image(game->mlx, PLAYER_PATH, &width, &length);
	game->map->t_wall = mlx_xpm_file_to_image(game->mlx, WALL_PATH, &width, &length);
}

void	affiche(t_mlx *mlx, t_texture *texture, int i, int j)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, texture, j * 64, i * 64);
}

static void affiche_map(t_mlx *game)
{
	int	i ;
	int	j ;
	
	i = -1;
	while (++i < game->jeu->dimensions->width)
	{
		j = -1;
		while (++j < game->jeu->dimensions->lenght)
		{
			if (game->jeu->map[i][j] == 'W')
				affiche(game, game->map->t_wall, i, j);
			else if (game->jeu->map[i][j] == 'G')
				affiche(game, game->map->t_ground, i, j);
			else if (game->jeu->map[i][j] == 'C')
				affiche(game, game->map->t_collectible, i, j);
			else if (game->jeu->map[i][j] == 'E')
				affiche(game, game->map->t_exit, i, j);
			else if (game->jeu->map[i][j] == 'P')
				affiche(game, game->map->t_player, i, j);
		}
	}
}

// Permet de faire une action en fonction de la touche pressee
int	hook_repartor(int keycode, t_mlx *game)
{
	int	count;

	count = game->count_mouvement;
	if ((keycode == 'w' || keycode == 'a' || keycode == 's' || keycode == 'd' 
		|| keycode == 65307)) 
	{
		if (keycode == 'w') // W
			moveUp(game, game->jeu->player->x, game->jeu->player->y);
		else if (keycode == 'a') // A
			moveLeft(game, game->jeu->player->x, game->jeu->player->y);
		else if (keycode == 's') // S
			moveDown(game, game->jeu->player->x, game->jeu->player->y);
		else if (keycode == 'd') // D
			moveRight(game, game->jeu->player->x, game->jeu->player->y);
		else if (keycode == 65307) // Echap
			ft_error_mlx("Manual stop of the game :/ you're so bad ... !", game);
		if (count != game->count_mouvement)
		{
			ft_printf("\rCompteur de mouvement : %d", game->count_mouvement);
			evolve_display(game, game->jeu->player->x, game->jeu->player->y);
		}	
	}
	return (1);
}

void	launch_game(t_mlx *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error_mlx("Probleme when allocating MLX pointer ! \n", game);
	game->win = mlx_new_window(game->mlx, game->jeu->dimensions->lenght * RES,
		game->jeu->dimensions->width * RES, game->jeu->name);
	if (!game->win)
		ft_error_mlx("Probleme when allocating Win pointer ! \n", game);
	charge_textures(game);
	affiche_map(game);
	game->left_items = game->jeu->info->collectibles;
	game->count_mouvement = 0;
	mlx_hook(game->win, KeyPress, KeyPressMask, &hook_repartor, game);
	// mlx_hook(game->win, 33, )
	// mlx_mouse_hook();
	mlx_loop(game->mlx);
}
