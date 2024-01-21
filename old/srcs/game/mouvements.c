/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:54:19 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/21 18:38:00 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	evolve_display(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->map->t_player, 
		y * RES, x * RES);
	if (mlx->last_movement == 1)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->map->t_ground, 
			y * RES, (x + 1) * RES);
	}
	else if (mlx->last_movement == 2)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->map->t_ground, 
			(y + 1) * RES, x * RES);
	}
	else if (mlx->last_movement == 3)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->map->t_ground, 
			y * RES, (x - 1) * RES);
	}
	else if (mlx->last_movement == 4)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->map->t_ground, 
			(y - 1) * RES, x * RES);
	}
}

// Function for when the player presses 'W'
void moveUp(t_mlx *mlx, int x, int y)
{
	if (mlx->jeu->map[x - 1][y] != 'W') 
	{
		if (mlx->jeu->map[x - 1][y] == 'C') 
		{
			mlx->left_items--;
			mlx->jeu->map[x - 1][y] = 'G';
		}
		else if (mlx->jeu->map[x - 1][y] == 'E')
		{
			if (mlx->left_items == 0)
				ft_error_mlx("\nGG, BG", mlx);
			return ;
		}
		if (1 == 1) 
		{
			mlx->jeu->map[x][y] = 'G';
			(x)--;
			mlx->jeu->map[x][y] = 'P';
		}
		mlx->last_movement = 1;
		mlx->count_mouvement++;
	}
	mlx->jeu->player->x = x;
	mlx->jeu->player->y = y;
}

// Function for when the player presses 'A'
void moveLeft(t_mlx *mlx, int x, int y)
{
	if (mlx->jeu->map[x][y - 1] != 'W') 
	{
		if (mlx->jeu->map[x][y - 1] == 'C') 
		{
			mlx->left_items--;
			mlx->jeu->map[x][y - 1] = 'G';
		}
		else if (mlx->jeu->map[x][y - 1] == 'E')
		{
			if (mlx->left_items == 0)
				ft_end_game(mlx);
			return ;
		}
		else 
		{
			mlx->jeu->map[x][y] = 'G';
			(y)--;
			mlx->jeu->map[x][y] = 'P';
		}
		mlx->last_movement = 2;
		mlx->count_mouvement++;
	}
	mlx->jeu->player->x = x;
	mlx->jeu->player->y = y;
}

// Function for when the player presses 'S'
void moveDown(t_mlx *mlx, int x, int y)
{
	if (mlx->jeu->map[x + 1][y] != 'W') 
	{
		if (mlx->jeu->map[x + 1][y] == 'C') 
		{
			mlx->left_items--;
			mlx->jeu->map[x + 1][y] = 'G';
		}
		else if (mlx->jeu->map[x + 1][y] == 'E')
		{
			if (mlx->left_items == 0)
				ft_end_game(mlx);
			return;
		}
		else 
		{
			mlx->jeu->map[x][y] = 'G';
			(x)++;
			mlx->jeu->map[x][y] = 'P';
		}
		mlx->last_movement = 3;
		mlx->count_mouvement++;
	}
	mlx->jeu->player->x = x;
	mlx->jeu->player->y = y;
}

// Function for when the player presses 'D'
void moveRight(t_mlx *mlx, int x, int y)
{
	if (mlx->jeu->map[x][y + 1] != 'W') 
	{
		if (mlx->jeu->map[x][y + 1] == 'C') 
		{
			(mlx->left_items)--;
			mlx->jeu->map[x][y + 1] = 'G';
		}
		else if (mlx->jeu->map[x][y + 1] == 'E')
		{
			if (mlx->left_items == 0)
				ft_end_game(mlx);
			return ;
		}
		else
		{
		mlx->jeu->map[x][y] = 'G';
		(y)++;
		mlx->jeu->map[x][y] = 'P';
		}
		mlx->last_movement = 4;
		mlx->count_mouvement++;
	}
	mlx->jeu->player->x = x;
	mlx->jeu->player->y = y;
}
