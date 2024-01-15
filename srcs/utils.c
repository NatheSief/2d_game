/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:11:44 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/12 10:03:49 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Retourne le nombre de lignes de ma map
int	ft_count_lines_char(char **map)
{
	int	size;

	size = 0;
	while (map[size])
		size ++;
	return (size);
}

// Permet de copier une map et effectuer ma vérification de path
char **char_tab_dup(t_map *map, t_map *new_map)
{
    char **dup;
    int i;

	i = 0;
    dup = malloc((ft_count_lines_char(map->map) + 1) * sizeof(char *)); // +1 pour le pointeur NULL final
    if (!dup)
    {
        free(new_map);
        ft_error("Erreur dans la vérification de la map \n", map);
    }
    while (i < ft_count_lines_char(map->map))
    {
        dup[i] = malloc(sizeof(char) * (ft_strlen(map->map[i]) + 1)); // +1 pour le caractère NULL final
        if (!dup[i])
        {
            libere(dup);
            free(new_map);
            ft_error("Erreur dans la vérification de la map \n", map);
        }
        dup[i] = ft_strdup(map->map[i]);
        i++;
    }
    dup[i] = NULL;
    return (dup);
}


void	ft_strcpy(char *dest, char *src, int size)
{
	int (i) = -1;
	
	while (++i < size)
		dest[i] = src[i];
	dest[i] = 0;
}

// Permet d'initialiser ma structure map
t_map	*init_map(void)
{
	t_map	*map;
	
	map = ft_calloc(sizeof(t_map), 1);
	map->name = NULL;
	map->map = NULL;
	map->dimensions = ft_calloc(sizeof(t_dimesions), 1);
	map->player = ft_calloc(sizeof(t_point), 1); 
	map->exit = ft_calloc(sizeof(t_point), 1); 
	map->info = ft_calloc(sizeof(t_count), 1); 
	return (map);
}

// Permet d'initialiser ma structure mlx
t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;
	
	mlx = ft_calloc(sizeof(t_mlx), 1);
	mlx->count_mouvement = 0;
	mlx->win = NULL;
	mlx->img = NULL;
	mlx->mlx = NULL;
	mlx->left_items = 0;
	mlx->player = ft_calloc(sizeof(t_point), 1);
	mlx->map = ft_calloc(sizeof(t_texture), 1);
	return (mlx);
}