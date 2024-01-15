/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:08:32 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/11 16:15:22 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error(char *str, t_map *map)
{
	ft_printf("%s\n", str);
	free(map);
	exit (1);
}

void	ft_error_print(char *str)
{
	ft_printf("%s\n", str);
	exit (1);
}

void libere(char **elem)
{
	int (i) = 0;
	while (elem[i])
	{
		free(elem[i]);
		i++;
	}
	free(dup);
}
