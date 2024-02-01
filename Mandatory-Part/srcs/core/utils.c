/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:11:44 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/28 15:46:58 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_to_up(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < LENGHT)
		{
			if (MAPS[i][j] >= 'a' && MAPS[i][j] <= 'z')
				MAPS[i][j] -= 32;
		}
	}
}

void	init_count(t_game *game)
{
	MAP->info->info->c_collectibles = 0;
	MAP->info->info->c_exit = 0;
	MAP->info->info->c_ground = 0;
	MAP->info->info->c_player = 0;
	MAP->info->info->c_wall = 0;
}

void	free_empty(t_game *game)
{
	ft_printf("Map is empty ! \n");
	free(MAP->info->dimensions);
	free(MAP->info->info);
	free(MAP->info);
	free(MAP);
	free(MLX);
	free(game);
}
