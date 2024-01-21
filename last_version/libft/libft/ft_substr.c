/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:40:17 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/12 19:42:29 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len + start > (ft_strlen(s)))
		len = ft_strlen(s) - start;
	str = (char *)malloc(len + 1);
	if (!str || !s)
		return (free(str), ft_strdup(""));
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
