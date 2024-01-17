/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:08:32 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/17 18:34:31 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error(char *str, t_map *map)
{
	ft_printf("%s\n", str);
	ft_free_map(map);
	exit (1);
}

void	ft_error_print(char *str)
{
	printf("error simple");
	ft_printf("%s\n", str);
	exit (1);
}

void libere(char **elem)
{
	int (i) = 0;
	while (elem[i])
	{
		free(elem[i]);
		i++;
	}
	free(dup);
}

void	ft_error_mlx(char *str, t_mlx *mlx)
{
	printf("Error MLX");
	ft_printf("%s\n", str);
	ft_free_mlx(mlx);
	exit (0);
}

void ft_end_game(t_mlx *mlx)
{
	if (mlx->map->t_wall != NULL)
		mlx_destroy_image(mlx, mlx->map->t_wall);
	if (mlx->map->t_ground != NULL)
		mlx_destroy_image(mlx, mlx->map->t_ground);
	if (mlx->map->t_collectible != NULL)
		mlx_destroy_image(mlx, mlx->map->t_collectible);
	if (mlx->map->t_exit != NULL)
		mlx_destroy_image(mlx, mlx->map->t_exit);
	if (mlx->map->t_player != NULL)
		mlx_destroy_image(mlx, mlx->map->t_player);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	ft_error_mlx("", mlx);
}
