/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:42:44 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/17 19:32:02 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	charge_textures(t_game *game)
{
	int	width;
	int	length;

	width = RES;
	length = RES;
	check_open(game);
	T_COLLECTIBLE = mlx_xpm_file_to_image(MLX, COLLECTIBLE_PATH, &width, &length);
	T_EXIT = mlx_xpm_file_to_image(MLX, EXIT_PATH, &width, &length);
	T_GROUND = mlx_xpm_file_to_image(MLX, GROUND_PATH, &width, &length);
	T_PLAYER = mlx_xpm_file_to_image(MLX, PLAYER_PATH, &width, &length);
	T_WALL = mlx_xpm_file_to_image(MLX, WALL_PATH, &width, &length);
}

static void affiche_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < LENGHT)
		{
			put_to_window(game, i, j);
		}
	}
}

// Permet de faire une action en fonction de la touche pressee
int	hook_repartor(int keycode, t_game *game)
{
	printf("Collectibles a recuperer : %d\n", INFO->coll_left);
	if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100 
		|| keycode == 65307 || keycode == 17)
	{
		
		if (keycode == 119) // W
			moveUp(game, PLAYER_P->x, PLAYER_P->y);
		else if (keycode == 97) // A
			moveLeft(game, PLAYER_P->x, PLAYER_P->y);
		else if (keycode == 115) // S
			moveDown(game, PLAYER_P->x, PLAYER_P->y);
		else if (keycode == 100) // D
			moveRight(game, PLAYER_P->x, PLAYER_P->y);
		else if (keycode == 65307) // Echap
			ft_error_free("Manal stop of the game :/ you're so bad ... !", game);
		evolve_display(game);
		ft_printf("Compteur de mouvement : %d\n", INFO->movement_count);
	}
	return (1);
}

void	launch_game(t_game *game)
{
	MLX = mlx_init();
	WIND = mlx_new_window(MLX, WIDTH * RES, LENGHT * RES, MAPS->name);
	charge_textures(game);
	affiche_map(game);
	mlx_hook(WIND, KeyPress, KeyPressMask, &hook_repartor, MLX);
	// mlx_mouse_hook();
	mlx_loop(MLX);
}
