/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:11:44 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/16 17:33:31 by nsiefert         ###   ########.fr       */
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
	
	map = malloc(sizeof(t_map));
	if (!map)
		ft_error_print("Probleme dans l'allocation de ma map");
	map->name = NULL;
	map->map = NULL;
	map->dimensions = malloc(sizeof(t_dimesions));
	if (!map->dimensions)
		ft_error("Probleme dans l'allocation de mes dims de la map", map);
	map->player = malloc(sizeof(t_point)); 
	if (!map->player)
		ft_error("Probleme dans l'allocation de mon joueur dans la map", map);
	map->exit = malloc(sizeof(t_point));
	if (!map->exit)
		ft_error("Probleme dans l'allocation de ma sortie dans la map", map);
	map->info = malloc(sizeof(t_count)); 
	if (!map->info)
		ft_error("Probleme dams l'allocation de mes infos dans la map", map);
	return (map);
}

// Permet d'initialiser ma structure mlx
t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;
	
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		ft_error_print("Probleme a l'allocation de mlx");
	mlx->win = NULL;
	mlx->img = NULL;
	mlx->mlx = NULL;
	mlx->count_mouvement = 0;
	mlx->left_items = 0;
	mlx->left_items = 0;
	mlx->count_mouvement = 0;
	mlx->map = malloc(sizeof(t_texture));
	mlx->player = malloc(sizeof(t_point));
	if (!mlx->player)
		ft_error_mlx("Probleme dans l'allocation du joueur de MLX", mlx);
	if (!mlx->map)
		ft_error_mlx("Probleme dans l'allocation de la map de MLX", mlx);
	mlx->jeu = init_map();	
	return (mlx);
}
