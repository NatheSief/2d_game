/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:55:46 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/22 15:04:38 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac == 1)
		ft_error("Program should execute with a map file !");
	if (ac > 2)
		ft_error("Program should execute with onyly one map file !");
	else
	{
		// INIT_STRUCTS
		// LAUNCH MAP
		// LAUNCH GAME
	}
	return (0);
}