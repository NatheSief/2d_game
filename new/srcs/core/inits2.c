/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:49:45 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/18 17:22:11 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_images(t_game *game)
{
	T_COLLECTIBLE = NULL;
	T_EXIT = NULL;
	T_GROUND = NULL;
	T_PLAYER = NULL;
	T_WALL = NULL;
}

void	init_pos(t_game *game)
{
	PLAYER_P = malloc(sizeof(int) * 2);
	if (!PLAYER_P)
		ft_error_free("Nique tes morts batard \n", game);
	PLAYER_P->x = 0;
	PLAYER_P->y = 0;
}

void	init_info(t_game *game)
{
	INFO->coll_left = 0;
	INFO->last_movement = 0;
	INFO->lenght = 0;
	INFO->movement_count = 0;
	INFO->width = 0;
	INFO->count = NULL;
	INFO->player_pos = NULL;
	init_elems(game);
	init_pos(game);
}
