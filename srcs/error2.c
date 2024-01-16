/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:36:22 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/16 17:41:26 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Free all the elements of my map struct
void	ft_free_map(t_map *map)
{
	free(map->dimensions);
	free(map->player);
	free(map->exit);
	free(map->info);
	free(map);
}

// Free all the elements of my mlx struct
void	ft_free_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free (mlx->player);
	free (mlx->map);
	ft_free_map(mlx->jeu);
	free (mlx);
}

