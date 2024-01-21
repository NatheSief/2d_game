/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:42:44 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/18 16:42:34 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	charge_textures(t_game *game)
{
	int	width;
	int	length;

	width = RES;
	length = RES;
	// check_open(game);
	T_COLLECTIBLE = mlx_xpm_file_to_image(MLX, COLLECTIBLE_PATH, &width, &length);
	T_EXIT = mlx_xpm_file_to_image(MLX, EXIT_PATH, &width, &length);
	T_GROUND = mlx_xpm_file_to_image(MLX, GROUND_PATH, &width, &length);
	T_PLAYER = mlx_xpm_file_to_image(MLX, PLAYER_PATH, &width, &length);
	T_WALL = mlx_xpm_file_to_image(MLX, WALL_PATH, &width, &length);
}

void	affiche(t_mlx *mlx, t_text *texture, int i, int j)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, texture, j * 64, i * 64);
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
			if (MAPS->map[i][j] == 'W')
				affiche(game->mlx, T_WALL, i, j);
			else if (MAPS->map[i][j] == 'G')
				affiche(game->mlx, T_GROUND, i, j);
			else if (MAPS->map[i][j] == 'C')
				affiche(game->mlx, T_COLLECTIBLE, i, j);
			else if (MAPS->map[i][j] == 'E')
				affiche(game->mlx, T_EXIT, i, j);
			else if (MAPS->map[i][j] == 'P')
				affiche(game->mlx, T_PLAYER, i, j);
		}
	}
}

// Permet de faire une action en fonction de la touche pressee
int	hook_repartor(int keycode, t_game *game)
{
	if ((keycode == 'w' || keycode == 'a' || keycode == 's' || keycode == 'd' 
		|| keycode == 65307)) 
	{
		ft_printf("\rCompteur de mouvement : %d\n", INFO->movement_count);
		if (keycode == 'w') // W
			moveUp(game, PLAYER_P->x, PLAYER_P->y);
		else if (keycode == 'a') // A
			moveLeft(game, PLAYER_P->x, PLAYER_P->y);
		else if (keycode == 's') // S
			moveDown(game, PLAYER_P->x, PLAYER_P->y);
		else if (keycode == 'd') // D
			moveRight(game, PLAYER_P->x, PLAYER_P->y);
		else if (keycode == 65307) // Echap
			ft_error_free("Manual stop of the game :/ you're so bad ... !", game);
		evolve_display(game);
	}
	return (1);
}

void	launch_game(t_game *game)
{
	MLX = mlx_init();
	if (!MLX)
		ft_error_free("Probleme when allocating MLX pointer ! \n", game);
	WIND = mlx_new_window(MLX, LENGHT * RES, WIDTH * RES, MAPS->name);
	if (!WIND)
		ft_error_free("Probleme when allocating Win pointer ! \n", game);
	charge_textures(game);
	affiche_map(game);
	INFO->coll_left = C_COLLECTIBLE;
	INFO->movement_count = 0;
	mlx_hook(WIND, KeyPress, KeyPressMask, &hook_repartor, game);
	// mlx_mouse_hook();
	mlx_loop(MLX);
}
