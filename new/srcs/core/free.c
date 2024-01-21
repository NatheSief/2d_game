/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:46:13 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/18 16:44:07 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = -1;
	while (MAPS->map[++i])
		free(MAPS->map[i]);
	free(MAPS->map);
	free(MAPS->name);
	free(MAPS);
}

void	free_images(t_game *game)
{
	if (T_COLLECTIBLE)
	{
		mlx_destroy_image(MLX, T_COLLECTIBLE);
		free(IMAGES->t_coll);
	}
	if (T_EXIT)
	{
		mlx_destroy_image(MLX, T_EXIT);
		free(IMAGES->t_exit);
	}
	if (T_GROUND)
	{
		mlx_destroy_image(MLX, T_GROUND);
		free(IMAGES->t_ground);
	}
	if (T_PLAYER)
	{
		mlx_destroy_image(MLX, T_PLAYER);
		free(IMAGES->t_player);
	}
	if (T_WALL)
	{
		mlx_destroy_image(MLX, T_WALL);
		free(IMAGES->t_wall);
	}
}

void	free_mlx(t_game *game)
{
	if (game->mlx)
	{
		if (IMAGES)
		{		
			free_images(game);
			free(IMAGES);
		}
		if (WIND)
		{
			mlx_destroy_window(MLX, WIND);	
			free(WIND);
		}
		{
		mlx_destroy_display(MLX);
		free(MLX);
	}
	if (game->mlx)
		free (game->mlx);
	}
}

void	free_info(t_game *game)
{
	free(COUNT);
	free(game->info->player_pos);
	free(game->info);
}

void	free_game(t_game *game)
{
	if (game->mlx != NULL)
		free_mlx(game);
	if (game->info != NULL)
		free_info(game);
	if (game->map != NULL)
		free_map(game);
	free(game);
}
