/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:18:43 by nsiefert          #+#    #+#             */
/*   Updated: 2024/02/01 14:34:48 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

//  Includes :

# include <stdlib.h>
# include <stdbool.h>

//  Structures :

typedef struct s_string t_string;

struct s_string
{
    char    **str;
    int     capacity;
    int     lenght;
};

//  Member functions
t_string *t_str_operator_equals(t_string *string);

int ft_str_length(t_string *string);
int ft_str_pop(t_string *string, char c);

//  Utils
int get_range_capacity(char *str);

#endif