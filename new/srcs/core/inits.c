/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:44:29 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/17 19:19:23 by nsiefert         ###   ########.fr       */
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
	if ((!(game->map) && garbage_init(game, game->map)) 
		|| (!(game->mlx) && malloc_garbage(game, game->mlx)) 
		|| (!(game->info) && malloc_garbage(game, game->info)))
		ft_error_free("Problems while allocating major structs!", game);
	game->mlx->img = malloc(sizeof(t_text));
	game->info->count = malloc(sizeof(t_count));
	game->info->player_pos = malloc(sizeof(t_point));
	if ((!(game->mlx->img) && malloc_garbage(game, IMAGES)) 
		|| ((!(game->info->count) && malloc_garbage(game, COUNT))) 
		|| (!(game->info->player_pos) && malloc_garbage(game, PLAYER_P)))
		ft_error_free("Problems while allocating minor structs !", game);
	return (game);
}

// Initiate the map struct, to stock map name and map content place
void	init_map(t_game *game, char *str)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map && malloc_garbage(game, game->map))
		ft_error_free("Problem when allocating map struct !", game);
	MAPS->name = malloc(sizeof(char) * (ft_strlen(ft_strrchr(str, '/')) - 4));
	MAPS->map = malloc(sizeof(char *) * WIDTH);
	if((!(MAPS->name) && malloc_garbage(game, MAPS->name)) 
		||(!(MAPS->map) && malloc_garbage(game, MAPS->map)))
		ft_error_free("Problem when allocating map tab or map name !", game);
}

void	init_mlx(t_game *game)
{
	game->mlx = malloc(sizeof(t_mlx));
	if (!game->mlx && malloc_garbage(game, game->mlx))
		ft_error_free("Probleme when allocating mlx struct !", game);
	game->mlx->img = malloc(sizeof(t_text));
	if (!game->mlx->img && malloc_garbage(game, game->mlx->img))
		ft_error_free("Probleme when allocating text struct !", game);
}

// Initiate the elements in my count struct
void	init_elems(t_game *game)
{
	C_COLLECTIBLE = 0;
	C_EXIT = 0;
	C_GROUND = 0;
	C_PLAYER = 0;
	C_WALL = 0;
}
