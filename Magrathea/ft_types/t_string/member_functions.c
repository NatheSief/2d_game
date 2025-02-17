/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   member_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:18:43 by nsiefert          #+#    #+#             */
/*   Updated: 2024/02/01 14:34:48 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_types.h"

t_string    *t_str_operator_equals(char *str)
{
    t_string    *new;
    int         i;

    new = malloc(sizeof(t_string));
    if (!new)
        return (NULL);
    new->capacity = get_range_capacity(str);
    new->lenght = ft_strlen(str);
    new->str = malloc(sizeof(char) * new->capacity);
    if (!new->str)
    {
        free(new);
        return (NULL);
    }
    i = -1;
    while (++i < new->lenght)
        new->str[i] = str[i];
    return (new);
}

bool    delete_str(t_string *str)
{
    free(str->str);
    free(str);
    return (true);
}

t_string    *new_str(void)
{
    t_string    *new;

    new = malloc(sizeof(t_string));
    if (!new)
        return (NULL);
    new->capacity = 10;
    new->lenght = 0;
    new->str = NULL;
    return (new);
}