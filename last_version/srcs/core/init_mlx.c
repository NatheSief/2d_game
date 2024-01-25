/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:24:35 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/25 13:15:23 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	init_texts(t_game *game)
{
	int	width;
	int	length;

	width = RES;
	length = RES;
	T_COLL = mlx_xpm_file_to_image(MLX->mlx, COLL_PATH, &width, &length);
	T_EXIT = mlx_xpm_file_to_image(MLX->mlx, EXIT_PATH, &width, &length);
	T_GROUND = mlx_xpm_file_to_image(MLX->mlx, GROUND_PATH, &width, &length);
	T_PLAYER = mlx_xpm_file_to_image(MLX->mlx, PLAYER_PATH, &width, &length);
	T_WALL = mlx_xpm_file_to_image(MLX->mlx, WALL_PATH, &width, &length);
	if (!(T_COLL && T_EXIT && T_GROUND && T_PLAYER && T_WALL))

		ft_error_free("Can't open a texture file !", game);
}

void	init_mlx(t_game *game)
{
	int	screen_x;
	int	screen_y;

	screen_x = 0;
	screen_y = 0;
	MLX->mlx = mlx_init();
	if (!MLX->mlx)
		ft_error_free("Problem while allocating mlx pointer !", game);
	// mlx_get_screen_size(MLX->mlx, &screen_x, &screen_y);
	// if (screen_x > LENGHT * RES || screen_y > WIDTH * 64)
	// 	ft_error_free("Map is to big for this window !\n", game);
	MLX->win= mlx_new_window(MLX->mlx, (LENGHT - 1) * RES, WIDTH * RES, MAP->name);
	MLX->texts = malloc(sizeof(void *) * 5);
	if (!MLX->win || !MLX->texts)
		ft_error_free("Problem while allocating the window !", game);
	init_texts(game);
}