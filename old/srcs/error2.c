/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:36:22 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/21 18:51:43 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Free all the elements of my map struct
void	ft_free_text(t_texture *map)
{
	if (map->t_wall)
		free(map->t_wall);
	if (map->t_player)
		free(map->t_player);
	if (map->t_exit)
		free(map->t_exit);
	if (map->t_ground)
		free(map->t_ground);
	if (map->t_collectible)
		free(map->t_collectible);
	free(map);
}

void	ft_free_map(t_map *map)
{
	if (map->name)
		free(map->name);
	if (map->map)
	{
		libere(map->map);
		free(map->map);
	}
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
	printf("freeing MLX pipou\n");
	if (mlx)
	{
		if (mlx->map)
			ft_free_text(mlx->map);
		if (mlx->jeu)
			ft_free_map(mlx->jeu);
		if (mlx->mlx)
			mlx_destroy_display(mlx->mlx);
		if (mlx->win)
			mlx_destroy_window(mlx->mlx, mlx->win);
		free (mlx);
	}
}
