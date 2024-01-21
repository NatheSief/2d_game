/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:59:44 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/18 12:20:46 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac < 2)
		ft_error("Le programme doit prendre une map en parametre !");
	if (ac > 2)
		ft_error("Le programme ne doit prendre qu'une map en parametre !");
	else
	{
		game = init_game();
		generate_map(av[1], game);
		launch_game(game);
		end_game(game);
	}
}
