/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:08:32 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/22 14:28:38 by nsiefert         ###   ########.fr       */
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
	ft_printf("%s\n", str);
	exit (1);
}

void libere(char **elem)
{
    int i;

    if (elem)
    {
        i = 0;
        while (elem[i])
        {
            free(elem[i]);
            i++;
        }
        free(elem);
    }
}

void	ft_error_mlx(char *str, t_mlx *mlx)
{
	ft_printf("%s\n", str);
	ft_end_game(mlx);
	exit (0);
}

void ft_end_game(t_mlx *mlx)
{
	ft_free_map(mlx->jeu);
	ft_free_mlx(mlx);
	free(mlx);
}
