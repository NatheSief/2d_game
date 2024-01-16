/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:15:20 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/16 10:08:53 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Permet d'avoir les dimesions de ma map, est de verifier que j'ai bien 
// un rectangle
void	check_dimensions(t_map *map, int fd)
{
	char	*line;
	int		comp;
	int		lenght;
	int		width;

	width = 0;
	line = get_next_line(fd);
	lenght = ft_strlen(line) - 1; // -1 pour retirer le \n
	while (line)
	{
		width++;
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		comp = ft_strlen(line) - 1;
		if (comp != lenght)
		{
			close (fd);
			free(line);
			ft_error("Les lignes ne sont pas de la meme longueur", map);
		}
	}
	map->dimensions->width = width;
	map->dimensions->lenght = lenght;
}

// Permet de comparer si la fin du nom de mon fichier est bien .ber
int		check_extension(char *str, char *ext)
{
	int	len;

	len = (int)ft_strlen(ext);
	if (!(ft_strncmp((const char*)(str + ft_strlen(str) - len), ext, len)))
		return (1);
	return (0);
}

//Permet d'allouer la map dans la structure
void	map_alloc(t_map *map, int fd)
{
	char	*line;
	int		i;

	map->map = malloc(sizeof(char *) * (map->dimensions->lenght + 1));
	if (!map->map)
		ft_error("Erreur lors de l'allocation de la map", map);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map->map[i] = NULL;
	close(fd);
}

void print_map(t_map *map)
{
	int i;

	i = 0;
	while (map->map[i] != NULL)
	{
		printf("%s\n", map->map[i]);
		i++;
	}
}

// Verifie toutes les informations de ma map et les enregistre dans les champs
// dedies dans les structures.
void	check_map(char *str, t_map *map)
{
	int		fd;

	fd = open(str, O_RDWR);
	if (!(check_extension(str, ".ber")))
		ft_error("Le fichier envoye n'est pas un .ber", map);
	if (fd == -1)
		ft_error("Le fichier n'existe pas", map);
	map->name = malloc(sizeof(char) * ((int)ft_strlen(str) - 4));
	ft_strlcpy(map->name, str, (int)ft_strlen(str) - 4);
	check_dimensions(map, fd);
	close(fd);
	fd = open(str, O_RDWR);
	map_alloc(map, fd);
	check_parse(map);
	check_map_info(map);
}
