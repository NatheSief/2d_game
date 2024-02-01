/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_inits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:11:05 by nsiefert          #+#    #+#             */
/*   Updated: 2024/02/01 12:14:15 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_map_pointers(t_game *game)
{
	game->map->info = NULL;
	game->map->map = NULL;
	game->map->name = NULL;
}

void	init_mlx_pointers(t_game *game)
{
	game->mlx->mlx = NULL;
	game->mlx->win = NULL;
	game->mlx->texts = NULL;
}
