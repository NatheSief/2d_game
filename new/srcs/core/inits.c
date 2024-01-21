/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:44:29 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/19 16:28:54 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Initiate the game structure at the beginning of the code, and also init the
// garbage collector
t_game	*init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_error("Problems while allocating general struct !");
	game->mlx = malloc(sizeof(t_mlx));
	game->info = malloc(sizeof(t_info));
	game->map = malloc(sizeof(t_map));
	if (!game->map || !game->mlx || !game->info)
		ft_error_free("Problems while allocating major structs!", game);
	game->mlx->img = malloc(sizeof(t_text));
	game->info->count = malloc(sizeof(t_count));
	game->info->player_pos = malloc(sizeof(t_point));
	if (!game->mlx->img	|| !game->info->count || !game->info->player_pos)
		ft_error_free("Problems while allocating minor structs !", game);
	init_info(game);
	return (game);
}

static	int get_dimesions(char *str)
{
	int		fd;
	char	*line;
	int 	count;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error("Problem while opening the map !");
	line = get_next_line(fd);
	count = 0;
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close (fd);
	return (count);
}

void init_map(t_game *game, char *str)
{
    game->map = malloc(sizeof(t_map)); // Allouer la mémoire pour la structure t_map
    if (!game->map)
        ft_error_free("Problem when allocating map struct !", game);
    MAPS->name = malloc(sizeof(char) * (ft_strlen(ft_strrchr(str, '/')) - 4));
    MAPS->map = malloc(sizeof(char *) * get_dimesions(str));
    if (!MAPS->name)
        ft_error_free("Problem when allocating map name !", game);
    if (!MAPS->map)
        ft_error_free("Problem when allocating map tab !", game);
}

void	init_mlx(t_game *game)
{
	game->mlx = malloc(sizeof(t_mlx));
	if (!game->mlx)
		ft_error_free("Probleme when allocating mlx struct !", game);
	game->mlx = NULL;
	game->mlx->img = malloc(sizeof(t_text));
	if (!game->mlx->img)
		ft_error_free("Probleme when allocating text struct !", game);
	game->mlx->img = NULL;
	game->mlx->mlx = NULL;
	game->mlx->win = NULL;
	init_images(game);
}

// Initiate the elements in my count struct
void	init_elems(t_game *game)
{
	COUNT = malloc(sizeof(int) * 5);
	if (!COUNT)
		ft_error_free("Et merde ... \n", game);
	C_COLLECTIBLE = 0;
	C_EXIT = 0;
	C_GROUND = 0;
	C_PLAYER = 0;
	C_WALL = 0;
}
