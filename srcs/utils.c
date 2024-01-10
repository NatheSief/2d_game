/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:11:44 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/08 11:27:18 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Retourne le nombre de lignes de ma map
int	ft_count_lines_char(char **map)
{
	int	size;

	size = 0;
	while (map[size][0])
		size ++;
	return (size);
}

// Permet de copier une map et effectuer ma verification de path
char **char_tab_dup(char **map)
{
	char	**dup;
	int		i;

	i = 0;
	dup = malloc(ft_count_lines_char(map) * sizeof(char *));
	while (dup[i])
	{
		dup[i] = ft_strdup(map[i]);
		i++;
	}
	return (dup);
}