/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:58:25 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/22 15:06:35 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	ft_free_struct(t_game *game)
{
	if (game->map)
		ft_free_map(game);
	if (game->mlx)
		ft_free_mlx(game);
	free(game);
}

// Affiche une erreur et free toute la structure derriere
void	ft_error_free(char *str, t_game *game)
{
	ft_printf("%s", str);
	ft_free_struct(game);
	exit (0);
}

// Affiche une erreur simple avant d'arreter le programme
void	ft_error(char *str)
{
	ft_printf("%s", str);
	exit(0);
}