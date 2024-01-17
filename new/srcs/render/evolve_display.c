/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evolve_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:00:14 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/17 19:07:26 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	evolve_display(t_game *game)
{
	mlx_put_image_to_window(MLX, WIND, T_PLAYER, PLAYER_P->x * RES,
		PLAYER_P->y * RES);
	if (INFO->last_movement == 1)
	{
		mlx_put_image_to_window(MLX, WIND, T_PLAYER, (PLAYER_P->x + 1) * RES,
		PLAYER_P->y * RES);
	}
	else if (INFO->last_movement == 2)
	{
		mlx_put_image_to_window(MLX, WIND, T_PLAYER, PLAYER_P->x * RES,
		(PLAYER_P->y + 1) * RES);
	}
	else if (INFO->last_movement == 3)
	{
		mlx_put_image_to_window(MLX, WIND, T_PLAYER, (PLAYER_P->x - 1) * RES,
		PLAYER_P->y * RES);
	}
	else if (INFO->last_movement == 4)
	{
		mlx_put_image_to_window(MLX, WIND, T_PLAYER, PLAYER_P->x * RES,
		(PLAYER_P->y - 1) * RES);
	}
}
