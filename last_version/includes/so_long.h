/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:49:35 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/22 15:06:50 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SLONG_H
# define SLONG_H

// Public headers
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>

// Private headers
# include "defines.h"
# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"

// Prototypes
// CORE - ERRORS
void	ft_error(char *str);
void	ft_error_free(char *str, t_game *game);

// CORE - FREE
void	ft_free_map(t_game *game);
void	ft_free_mlx(t_game *game);
#endif