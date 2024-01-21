/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:00:22 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/19 16:28:37 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_LONG_H
# define S_LONG_H

# include "./defines.h"

// CORE - ERRORS_DISPLAY
void	ft_error(char *str);
void	ft_error_free(char *str, t_game *game);
void	end_game(t_game *game);
// CORE - FREE
void	free_game(t_game *game);
void	free_info(t_game *game);
void	free_mlx(t_game *game);
void	free_map(t_game *game);
// CORE - INITS
t_game	*init_game(void);
void	init_map(t_game *game, char *str);
void	init_mlx(t_game *game);
void	init_elems(t_game *game);
// CORE - INITS2
void	init_images(t_game *game);
void	init_info(t_game *game);
// CORE - UTILS2
void	init_images(t_game *game);
void	put_to_up(t_game *game);
// CORE - UTILS
void	put_to_window(t_game *game, int i, int j);
void	check_open(t_game *game);
t_game	*copy_info(t_game *original);
// CORE - UTILS 2
t_count *cpy_info(void);

// MAPS - GENERATE_MAP
void	generate_map(char *str, t_game *game);

// PARSING - PARSING
void	check_parsing(t_game *game);
// PARSING - PATH
void	check_path(t_game *game);
void	dfs(t_game *game, int i, int j);

// RENDER - LAUNCH_GAME
void	launch_game(t_game *game);
// RENDER - MOUVEMENTS
void moveUp(t_game *game, int x, int y);
void moveDown(t_game *game, int x, int y);
void moveLeft(t_game *game, int x, int y);
void moveRight(t_game *game, int x, int y);
// RENDER - EVOLVE_DISPLAY
void	evolve_display(t_game *game);


void	print_infos_game(t_game *game);

#endif