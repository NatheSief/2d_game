/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:16:49 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/17 18:25:21 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	put_to_window(t_game *game, int i, int j)
{
	if (MAPS->map[i][j] == 'C')
		mlx_put_image_to_window(MLX, WIND, T_COLLECTIBLE, i * RES, j * RES);
	else if (MAPS->map[i][j] == 'E')
		mlx_put_image_to_window(MLX, WIND, T_EXIT, i * RES, j * RES);
	else if (MAPS->map[i][j] == 'G')
		mlx_put_image_to_window(MLX, WIND, T_GROUND, i * RES, j * RES);
	else if (MAPS->map[i][j] == 'P')
		mlx_put_image_to_window(MLX, WIND, T_PLAYER, i * RES, j * RES);
	else if (MAPS->map[i][j] == 'W')
		mlx_put_image_to_window(MLX, WIND, T_WALL, i * RES, j * RES);
	
}

void	check_open(t_game *game)
{
	int fd1;
	int fd2;
	int fd3;
	int fd4;
	int fd5;
		
	fd1 = open(T_COLLECTIBLE, O_RDONLY);
	fd2 = open(T_COLLECTIBLE, O_RDONLY);
	fd3 = open(T_COLLECTIBLE, O_RDONLY);
	fd4 = open(T_COLLECTIBLE, O_RDONLY);
	fd5 = open(T_COLLECTIBLE, O_RDONLY);
	if (fd1 == -1 || fd2 == -1 || fd3 == -1 || fd4 == -1 || fd5 == -1)
		ft_error_free("We can't open .XPM files bitch !", game);
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	close(fd5);
}
