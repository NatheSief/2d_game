/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:07:03 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/27 11:27:26 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Permet d'allouer ma map dans ma structure
void	map_alloc(t_game *game, int fd)
{
	int	i;
	char *line;
	
	if (MAPS)
	{
		i = -1;
		// printf("WIDTH = %d\n", WIDTH);
		while (++i  < WIDTH + 1)
		{
			line = get_next_line(fd);
			if (!line)
				break;
			MAPS[i] = malloc(sizeof(char) * LENGHT + 1);
			if (!MAPS[i])
			{
				close(fd);
				ft_error_free("Problems while making map !", game);
			}
			ft_strlcpy(MAPS[i], line, (size_t)(LENGHT + 1));//ft_strdup(line);
			free(line);
		}
		MAPS[i] = 0;
	}
}

// Permet d'alloc le bon nom dans ma structure, ou d'envoyer la chaine de 
// caracteres pour malloc la bonne taille.
char	*get_name(t_game *game, char *str)
{
	char	*line;
	char	*stock;
	int		i;

	i = -1;
	stock = ft_strdup(str);
	line = (char *)calloc(ft_strlen(str + 3), sizeof(char));
	if (!line)
		ft_error_free("Problem while creating the map name !", game);
	while(++i < (int)ft_strlen(str + 4))
		line[i] = str[i];
	line[i] = 0;
	MAP->name = ft_strdup(line);
	free(line);
	free(stock);
	return (NULL);
}
