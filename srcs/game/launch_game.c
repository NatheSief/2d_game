/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:12:54 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/10 11:51:22 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Charge toutes les textures de mes elements
void	charge_textures(t_map *map, t_mlx *mlx)
{
	mlx->map->t_wall = mlx_xpm_file_to_image(mlx->mlx,
		 "../../textures/wall.xpm", 32, 32);
	mlx->map->t_collectible = mlx_xpm_file_to_image(mlx->mlx,
		 "../../textures/collectible.xpm", 32, 32);
	mlx->map->t_player = mlx_xpm_file_to_image(mlx->mlx,
		 "../../textures/player.xpm", 32, 32);
	mlx->map->t_exit = mlx_xpm_file_to_image(mlx->mlx,
		 "../../textures/exit.xpm", 32, 32);
	mlx->map->t_ground = mlx_xpm_file_to_image(mlx->mlx,
		 "../../textures/ground.xpm", 32, 32);

} 

// Lance le lancement du jeu, l'ouverture de ma fenetre, la generation des 
// sprites de la map de base, puis fait une boucle qui gere toutes les actions
// en fonction des actions du joueur 
void	launch_game(t_map *map, t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, map->dimensions->lenght*32, 
		map->dimensions->width*32, map->name);
	charge_textures(map, mlx);
	mlx_key_hook(mlx->mlx, );
	mlx_loop(mlx->mlx);
}
