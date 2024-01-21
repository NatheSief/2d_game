/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:16:52 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/19 16:37:05 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_count *cpy_info(void)
{
	t_count	*cpy;

	cpy = malloc(sizeof(int) * 5);
	if (!cpy)
		return (NULL);
	cpy->count_coll = 0;
	cpy->count_exit = 0;
	cpy->count_ground = 0;
	cpy->count_player = 0;
	cpy->count_wall= 0;
	return (cpy);
}

void put_to_up(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < LENGHT)
		{
			printf(" i = %d\n", i);
			printf(" j = %d\n", i);
			printf(" elem = %c\n\n", MAPS->map[i][j]);
			if (MAPS->map[i][j] >= 'a' && MAPS->map[i][j] <= 'z')
			{
				printf("%c \n", MAPS->map[i][j] += 32);
				MAPS->map[i][j] += 32;
			}
			printf(" new elem = %c\n\n", MAPS->map[i][j]);
		}
	}
	printf("Big boy now hehe \n %d, %d \n", WIDTH, LENGHT);
}
