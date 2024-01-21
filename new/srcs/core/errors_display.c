/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:20:00 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/18 15:05:53 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit(EXIT_SUCCESS);
}

void	ft_error_free(char *str, t_game *game)
{
	ft_printf("%s\n", str);
	free_game(game);
	exit(1);
}

void	end_game(t_game *game)
{
	ft_printf("GG BG\n");
	free_game(game);
	exit(0);
}
