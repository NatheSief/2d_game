/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:15:20 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/10 10:39:29 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Compte le nombre de lignes dans ma map
int	ft_count_lines(int fd)
{
	int		count;
	char	*temp;

	temp = get_next_line(fd);
	count = 1;
	while (temp)
	{
		free(temp);
		count++;
		temp = get_next_line(fd);
	}
	return (count);
}

// Recupere le nombre de colonnes dans ma map et verifie que toutes les lignes
// font la meme taille
int	line_lenght(int fd)
{
	int		lenght;
	int		comp;
	char	*temp;

	temp = get_next_line(fd);
	lenght = ft_strlen((const char)temp);
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
		comp = ft_strlen(temp);
		if (comp != lenght)
		{
			free(temp);
			ft_error_print("Les lignes ne sont pas de la meme taille.");
		}
	}
	return (lenght);
}

// Alloue chaque ligne de ma map en .ber dans ma chaine de caracteres
void	map_alloc(char **map, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	map[i] = line;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		map[++i] = line;
	}
}

// Permet de comparer si la fin du nom de mon fichier est bien .ber
int		check_extension(char *str, char *ext)
{
	int	len;

	len = (int)ft_strlen(ext);
	if (!(ft_strncmp((const char)(str + ft_strlen(str) - len), ext, len)))
		return (1);
	return (0);
}

// Verifie toutes les informations de ma map et les enregistre dans les champs
// dedies dans les structures.
void	check_map(char *str)
{
	int		fd;
	t_map	*map;

	fd = open(str, O_RDWR);
	if (!(check_extension(str, ".ber")))
		ft_error("Le fichier envoye n'est pas un .ber", map);
	ft_strlcpy(map->name, str, ft_strlen(str) - 4);
	map->dimensions->width = ft_count_lines(fd);
	map->dimensions->lenght = line_lenght(fd);
	map->map = malloc(sizeof(t_map));
	map_alloc(map->map, fd);
	check_parse(map);
	check_path(map);
}
