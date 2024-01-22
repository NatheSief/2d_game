/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:36:22 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/22 14:14:41 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Free all the elements of my map struct
void	ft_free_text(t_mlx *mlx)
{
	if (mlx->map->t_wall)
		mlx_destroy_image(mlx->mlx, mlx->map->t_wall);
	if (mlx->map->t_player)
		mlx_destroy_image(mlx->mlx, mlx->map->t_player);
	if (mlx->map->t_exit)
		mlx_destroy_image(mlx->mlx, mlx->map->t_exit);
	if (mlx->map->t_ground)
		mlx_destroy_image(mlx->mlx, mlx->map->t_ground);
	if (mlx->map->t_collectible)
		mlx_destroy_image(mlx->mlx, mlx->map->t_collectible);
	free(mlx->map);
}

void	ft_free_map(t_map *map)
{
	if (map->name)
		free(map->name);
	if (map->map)
	{
		libere(map->map);
	}
	free(map->map);
	// if (map->map)
	// 	printf("NULLOS !!! \n");
	if (map->dimensions)
		free(map->dimensions);
	if (map->player)
		free(map->player);
	if (map->exit)
		free(map->exit);
	if (map->info)
		free(map->info);
	free(map);
}

// Free all the elements of my mlx struct
void	ft_free_mlx(t_mlx *mlx)
{
	if (mlx)
	{
		if (mlx->map)
			ft_free_text(mlx);
		if (mlx->jeu)
			ft_free_map(mlx->jeu);
		if (mlx->win)
			mlx_destroy_window(mlx->mlx, mlx->win);
		if (mlx->mlx)
			mlx_destroy_display(mlx->mlx);
		free (mlx);
	}
}
