/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:19:56 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/17 19:37:09 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	check_top_bottom(t_game *game)
{
	int	i;

	i = 0;
	while (i < LENGHT)
	{
		if (MAPS->map[0][i] != 'W' || MAPS->map[WIDTH - 1][i] != 'W')
		{
			printf("%d -- %d\n", i, WIDTH);
			ft_error_free("There is a missing wall in the outline top!", game);
		}
		i++;
	}
}

static void	check_sides(t_game *game)
{
	int	i;

	i = 1;
	while (i < WIDTH - 1)
	{
		if (MAPS->map[i][0] != 'W' || MAPS->map[i][LENGHT - 1] != 'W')
			ft_error_free("There is a missing wall in the outline !", game);
		i++;
	}
}

static void	alloc_elems(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < LENGHT)
		{
			if (MAPS->map[i][j] == 'W')
				C_WALL ++;
			else if (MAPS->map[i][j] == 'G')
				C_GROUND++;
			else if (MAPS->map[i][j] == 'C')
				C_COLLECTIBLE++;
			else if (MAPS->map[i][j] == 'P')
				C_PLAYER++;
			else if (MAPS->map[i][j] == 'E')
				C_EXIT++;
		}
	}
}

static void	check_elems(t_game *game)
{
	int	sum;

	if (C_PLAYER != 1)
		ft_error_free("The amount of player is innapropriate !", game);
	if (C_EXIT != 1)
		ft_error_free("The amount of exit is innapropriate !", game);
	if (C_COLLECTIBLE < 1)
		ft_error_free("The amount of collectibles is innapropriate !", game);
	sum = WIDTH * LENGHT;
	if (sum != C_COLLECTIBLE + C_GROUND + C_WALL + 2)
		ft_error_free("There are innapropriate elements in the map !", game);
}

void	check_parsing(t_game *game)
{
	check_top_bottom(game);
	check_sides(game);
	init_elems(game);
	alloc_elems(game);
	check_elems(game);
	check_path(game);
}
