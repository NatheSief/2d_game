/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:49:35 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/26 10:08:51 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SLONG_H
# define SLONG_H

// Public headers
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <assert.h>

// Private headers
# include "defines.h"
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../minilibx-linux/mlx.h"

// Prototypes
// CORE - ERRORS
void	ft_error(char *str);
void	ft_error_free(char *str, t_game *game);

// CORE - FREE
void	ft_free_map(t_game *game);
void	ft_free_mlx(t_game *game);

// CORE - INITS
void	map_alloc(t_game *game, int fd);
char	*get_name(t_game *game, char *str);
t_game	*init_game(t_game *game, char *str);
void	init_mlx(t_game *game);

// CORE - UTILS
void	put_to_up(t_game *game);

// RENDER
void	launch_game(t_game *game);
void	evolve_display(t_game *game, int x, int y);
void	moveUp(t_game *game, int x, int y);
void	moveLeft(t_game *game, int x, int y);
void	moveRight(t_game *game, int x, int y);
void	moveDown(t_game *game, int x, int y);

// CHECK INFO
void	check_map(t_game *game);
void	check_path(t_game *game);
#endif