/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:24:35 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/23 15:35:19 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	init_texts(t_game *game)
{
	int	fd[5];
	int	width;
	int	length;

	width = RES;
	length = RES;
	fd[0] = open(COLL_PATH, O_RDONLY);
	fd[1] = open(EXIT_PATH, O_RDONLY);
	fd[2] = open(GROUND_PATH, O_RDONLY);
	fd[3] = open(PLAYER_PATH, O_RDONLY);
	fd[4] = open(WALL_PATH, O_RDONLY);
	if (!(fd[0] && fd[1] && fd[2] && fd[3] && fd[4]))
		ft_error_free("Can't open a texture file !", game);
	T_COLL = mlx_xpm_file_to_image(MLX->mlx, COLL_PATH, &length, &width);
	T_EXIT = mlx_xpm_file_to_image(MLX->mlx, EXIT_PATH, &length, &width);
	T_GROUND = mlx_xpm_file_to_image(MLX->mlx, GROUND_PATH, &length, &width);
	T_PLAYER = mlx_xpm_file_to_image(MLX->mlx, PLAYER_PATH, &length, &width);
	T_WALL = mlx_xpm_file_to_image(MLX->mlx, WALL_PATH, &length, &width);
	(close(fd[0]), close(fd[1]), close(fd[2]), close(fd[3]), close(fd[4]));
}

void	init_mlx(t_game *game)
{
	MLX->mlx = mlx_init();
	if (!MLX->mlx)
		ft_error_free("Problem while allocating mlx pointer !", game);
	MLX->win= mlx_new_window(MLX->mlx, LENGHT, WIDTH, MAP->name);
	MLX->texts = malloc(sizeof(void *) * 5);
	if (!MLX->win || !MLX->texts)
		ft_error_free("Problem while allocating the window !", game);
	init_texts(game);
}