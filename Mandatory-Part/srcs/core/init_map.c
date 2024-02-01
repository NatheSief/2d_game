/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:37:58 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/28 15:47:23 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Permet d'update les counts de ma map -> nombre de chaque elements, ainsi que
// de verifier que je n'ai que des elements connus
static void	update_info(t_game *game, char *str)
{
	int	i;

	i = -1;
	while (str[++i + 1])
	{
		if (str[i] == 'C')
			MAP->info->info->c_collectibles++;
		else if (str[i] == 'E')
			MAP->info->info->c_exit++;
		else if (str[i] == 'G')
			MAP->info->info->c_ground++;
		else if (str[i] == 'P')
			MAP->info->info->c_player++;
		else if (str[i] == 'W')
			MAP->info->info->c_wall++;
		else
			ft_error_free("There is a unknown character on the map !", game);
	}
}

// Permet de recuperer les dimensions de ma map
static int	get_dimensions_info(t_game *game, int fd)
{
	int		comp;
	int		lenght;
	char	*line;
	int		widht;

	line = get_next_line(fd);
	widht = 0;
	if (!line)
		return (0);
	while (line)
	{
		lenght = ft_strlen(line);
		comp = ft_strlen(line);
		if (comp != lenght)
			return (close(fd), ft_error_free("Line different size !", game), 0);
		update_info(game, line);
		free(line);
		line = get_next_line(fd);
		WIDTH = ++widht;
		LENGHT = lenght;
	}
	free(line);
	return (1);
}

// Permet d'initier la structure INFO
static void	init_info(t_game *game, char *str)
{
	int	fd;

	MAP->info->dimensions = NULL;
	MAP->info->dimensions = malloc(sizeof(t_point));
	if (!MAP->info->dimensions)
		ft_error_free("Problem while allocating dimensions ! \n", game);
	MAP->info->player.x = 0;
	MAP->info->player.y = 0;
	MAP->info->info = ft_calloc(1, sizeof(t_count));
	if (!MAP->info->info)
		ft_error_free("Problem while allocating informations ! \n", game);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error_free("Can't open map file !\n", game);
	if (!get_dimensions_info(game, fd))
	{
		free_empty(game);
		exit(1);
	}
	close (fd);
}

// Permet d'initier la structure MAP
static void	init_map(t_game *game, char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error_free("Can't open the map file !", game);
	MAP->info = NULL;
	MAP->info = malloc(sizeof(t_info));
	ft_memset(MAP->info, 0, sizeof(t_info));
	if (!MAP->info)
		ft_error_free("Problen while allocating infos !", game);
	init_info(game, str);
	MAP->map = NULL;
	game->map->map = malloc(sizeof(char *) * (WIDTH + 1));
	MAP->map[WIDTH] = NULL;
	if (!MAP->map)
		ft_error_free("Problem while allocatin map or name !\n", game);
	MAP->name = NULL;
	get_name(game, str);
	map_alloc(game, fd);
}

// Permet d'initier la strcture GAME
t_game	*init_game(t_game *game, char *str)
{
	game = malloc(sizeof(t_game));
	if (!game)
		ft_error("Problem while allocating structure game !");
	game->map = NULL;
	game->mlx = NULL;
	game->map = malloc(sizeof(t_map));
	game->mlx = malloc(sizeof(t_mlx));
	if (!game->map || !game->mlx)
		ft_error_free("Problem while allocating game in-structures !", game);
	init_map(game, str);
	init_mlx(game);
	return (game);
}
