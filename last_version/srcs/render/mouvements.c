/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:54:19 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/23 17:06:34 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	evolve_display(t_game *game, int x, int y)
{
	int	width;
	int	length;

	width = RES;
	length = RES;
	mlx_put_image_to_window(MLX->mlx, MLX->win, MLX->texts->t_player, 
		y * RES, x * RES);
	if (MAP->info->last_mouvement == 1)
		mlx_put_image_to_window(MLX->mlx, MLX->win, MLX->texts->t_ground, 
			y * RES, (x + 1) * RES);
	else if (MAP->info->last_mouvement == 2)
		mlx_put_image_to_window(MLX->mlx, MLX->win, MLX->texts->t_ground, 
			(y + 1) * RES, x * RES);
	else if (MAP->info->last_mouvement == 3)
		mlx_put_image_to_window(MLX->mlx, MLX->win, MLX->texts->t_ground, 
			y * RES, (x - 1) * RES);
	else if (MAP->info->last_mouvement == 4)
		mlx_put_image_to_window(MLX->mlx, MLX->win, MLX->texts->t_ground, 
			(y - 1) * RES, x * RES);
}

// Function for when the player presses 'W'
void	moveUp(t_game *game, int x, int y)
{
	if (MAPS[x - 1][y] != 'W') 
	{
		if (MAPS[x - 1][y] == 'C') 
		{
			MAP->info->left_items--;
			MAPS[x - 1][y] = 'G';
		}
		else if (MAPS[x - 1][y] == 'E')
		{
			if (MAP->info->left_items == 0)
				ft_error_free("GG, BG", game);
			return ;
		}
		if (1 == 1) 
		{
			MAPS[x][y] = 'G';
			(x)--;
			MAPS[x][y] = 'P';
		}
		MAP->info->last_mouvement = 1;
		MAP->info->count_mouvements++;
	}
	MAP->info->player.x = x;
	MAP->info->player.y = y;
}

// Function for when the player presses 'A'
void	moveLeft(t_game *game, int x, int y)
{
	if (MAPS[x][y - 1] != 'W') 
	{
		if (MAPS[x][y - 1] == 'C') 
		{
			MAP->info->left_items--;
			MAPS[x][y - 1] = 'G';
		}
		else if (MAPS[x][y - 1] == 'E')
		{
			if (MAP->info->left_items == 0)
				ft_error_free("GG BG !!!", game);
			return ;
		}
		else 
		{
			MAPS[x][y] = 'G';
			(y)--;
			MAPS[x][y] = 'P';
		}
		MAP->info->last_mouvement = 2;
		MAP->info->count_mouvements++;
	}
	MAP->info->player.x = x;
	MAP->info->player.y = y;
}

// Function for when the player presses 'S'
void	moveDown(t_game *game, int x, int y)
{
	if (MAPS[x + 1][y] != 'W') 
	{
		if (MAPS[x + 1][y] == 'C') 
		{
			MAP->info->left_items--;
			MAPS[x + 1][y] = 'G';
		}
		else if (MAPS[x + 1][y] == 'E')
		{
			if (MAP->info->left_items == 0)
				ft_error_free("GG BG !!!", game);
			return;
		}
		else 
		{
			MAPS[x][y] = 'G';
			(x)++;
			MAPS[x][y] = 'P';
		}
		MAP->info->last_mouvement = 3;
		MAP->info->count_mouvements++;
	}
	MAP->info->player.x = x;
	MAP->info->player.y = y;
}

// Function for when the player presses 'D'
void	moveRight(t_game *game, int x, int y)
{
	if (MAPS[x][y + 1] != 'W') 
	{
		if (MAPS[x][y + 1] == 'C') 
		{
			(MAP->info->left_items)--;
			MAPS[x][y + 1] = 'G';
		}
		else if (MAPS[x][y + 1] == 'E')
		{
			if (MAP->info->left_items == 0)
				ft_error_free("GG BG !!!", game);
			return ;
		}
		else
		{
		MAPS[x][y] = 'G';
		(y)++;
		MAPS[x][y] = 'P';
		}
		MAP->info->last_mouvement = 4;
		MAP->info->count_mouvements++;
	}
	MAP->info->player.x = x;
	MAP->info->player.y = y;
}
