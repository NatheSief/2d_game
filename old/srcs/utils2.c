/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:27:57 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/21 13:42:39 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	remake(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->dimensions->width)
	{
		j = -1;
		while (++j < map->dimensions->lenght)
		{
			ft_toupper(map->map[i][j]);
		}
	}
}

void put_to_up(t_map *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->dimensions->width)
	{
		j = -1;
		while (++j < game->dimensions->lenght)
		{
			if (game->map[i][j] >= 'a' && game->map[i][j] <= 'z')
				game->map[i][j] -= 32;
		}
	}
}