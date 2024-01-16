/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:08:32 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/16 11:47:04 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error(char *str, t_map *map)
{
	ft_printf("%s\n", str);
	free(map);
	exit (1);
}

void	ft_error_print(char *str)
{
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

void ft_end_game(t_mlx *mlx)
{
	printf("LE JEU S'ARRETTE SALOPES");
	int	i;
	int j;

	i = 0;
	while (i <= mlx->jeu->dimensions->width)
	{
		j = 0;
		while (j <= mlx->jeu->dimensions->lenght)
		{
			mlx_destroy_image(mlx->mlx, mlx->map);
			j++;
		}
		i++;
	}
	mlx_destroy_window(mlx->mlx, mlx->win);
	free(mlx);
}

void	ft_error_mlx(char *str, t_mlx *mlx)
{
	ft_printf("%s\n", str);
	free (mlx);
}