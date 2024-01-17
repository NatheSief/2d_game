/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:35:06 by nsiefert          #+#    #+#             */
/*   Updated: 2023/12/19 20:33:44 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_check_space(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static int	ft_check_sign(const char *nptr, int *i)
{
	while (ft_check_space(nptr[*i]))
		(*i)++;
	if (nptr[*i] == '-')
	{
		(*i)++;
		return (-1);
	}
	else if (nptr[*i] == '+')
		(*i)++;
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = ft_check_sign(nptr, &i);
	number = 0;
	while (nptr[i])
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			number = (number * 10) + nptr[i] - '0';
		else
			break ;
		i++;
	}
	return (sign * number);
}
