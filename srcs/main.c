/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:06:12 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/15 17:50:42 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_mlx	*(mlx) = init_mlx();
	t_map	*(map) = init_map();

	if (ac < 2)
		ft_error_print("Il faut entrer une map pour la jouer.");
	else if (ac > 2)
		ft_error_print("Il ne faut pas entrer plus d'une map.");
	else
	{
		check_map(av[1], map);
		mlx->jeu = map;
		launch_game(mlx);
	}
	free(mlx);
}
