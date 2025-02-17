/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:18:43 by nsiefert          #+#    #+#             */
/*   Updated: 2024/02/01 14:34:48 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_types.h"

int get_range_capacity(char *str)
{
    int i;
    int capacity;

    i = -1;
    while (str[++i])
        continue;
    capacity = 10;
    while (i--)
        capacity *= capacity;
    return (capacity);
}