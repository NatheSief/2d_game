/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:07:03 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/23 11:22:10 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Permet d'allouer ma map dans ma structure
void	map_alloc(t_game *game, int fd)
{
	int	i;
	
	if (MAPS)
	{
		i = -1;
		while (++i <= WIDTH)
		{
			MAPS[i] = malloc(sizeof(char) * LENGHT);
			if (!MAPS[i])
			{
				close(fd);
				ft_error_free("Problems while making map !", game);
			}
			MAPS[i] = ft_strdup(get_next_line(fd));
		}
	}
}

// Permet de remove l'extension de mon nom de fichier
static char	*ft_remove_ext(char *str)
{
	int	i;
	int	pos;
	char *line;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '.')
			pos = i;
	}
	line = malloc(sizeof(char) * pos);
	if (!line)
		return (NULL);
	i = -1;
	while (line[++i] && str[++i] != '.')
		line[i] = str[i];
	line[i] = 0;
	return (line);
}

// Permet d'alloc le bon nom dans ma structure, ou d'envoyer la chaine de 
// caracteres pour malloc la bonne taille.
char *get_name(t_game *game, char *str)
{
	char *line;

	line = malloc(sizeof(char) * ft_strlen(ft_strrchr(str, '/') - 4));
	line = ft_remove_ext(ft_strrchr(str, '/'));
	if (!line)
		ft_error_free("Problem while creating the map name !", game);
	if (!MAP->name)
		return(line);
	MAP->name = ft_strdup(line);
	free(line);
	return (NULL);
}
