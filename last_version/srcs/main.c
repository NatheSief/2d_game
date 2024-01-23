/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:55:46 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/23 19:12:13 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	game = NULL;
	if (ac == 1)
		ft_error("Program should execute with a map file !");
	if (ac > 2)
		ft_error("Program should execute with onyly one map file !");
	else
	{
		if (!ft_countchar(av[1], '.'))
			ft_error("File doesn't have a valid name (multiple dots) !");
		init_game(game, av[1]);
		check_map(game);
		launch_game(game);
	}
	return (0);
}