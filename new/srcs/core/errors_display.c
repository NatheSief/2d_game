/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:20:00 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/17 12:16:09 by nsiefert         ###   ########.fr       */
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
	empty_the_bin(game);
	exit(1);
}

void	end_game(t_game *game)
{
	ft_printf("GG BG\n");
	empty_the_bin(game);
}
