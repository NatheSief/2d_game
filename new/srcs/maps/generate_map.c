/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:34:49 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/19 16:29:58 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void get_dimesions(int fd, t_game *game)
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
			ft_error_free("Lines are not the same sizes !", game);
		}
	}
	INFO->width = width;
	INFO->lenght = lenght;
}

static void	map_alloc(t_game *game, int fd)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		MAPS->map[i] = malloc(sizeof(char) * LENGHT);
		if (!MAPS->map[i])
			ft_error_free("Problem during map allocation ! \n", game);
		MAPS->map[i] = ft_strdup(get_next_line(fd));
		i++;
	}
	if (i < WIDTH - 1)
	{
		close (fd);
		ft_error_free("J'en peux plus sa mere \n", game);
	}
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

void	get_position_player(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < LENGHT)
		{
			if (MAPS->map[i][j] == 'P')
			{
				PLAYER_P->x = i;
				PLAYER_P->y = j;
			}
		}
	}
}

void	generate_map(char *str, t_game *game)
{
	int		fd;

	if (!check_extension(str, ".ber"))
		ft_error_free("File isn't a .ber !", game);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error_free("File can't be opened !", game);
	get_dimesions(fd, game);
	close(fd);
	fd = open(str, O_RDONLY);
	init_map(game, str);
	map_alloc(game, fd);
	close(fd);
	get_position_player(game);
	check_parsing(game);
}
