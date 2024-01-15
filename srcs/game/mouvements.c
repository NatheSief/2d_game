/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:54:19 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/15 18:05:27 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Function for when the player presses 'W'
void moveUp(t_mlx *mlx, int x, int y) 
{
	if (mlx->jeu->map[x - 1][y] != 'W') {
		if (mlx->jeu->map[x - 1][y] == 'C') {
			(mlx->left_items)--;
			mlx->jeu->map[x - 1][y] = 'G';
		}
		mlx->jeu->map[x][y] = 'G';
		(x)--;
		mlx->jeu->map[x][y] = 'P';
	}
	(mlx->count_mouvement)++;
}

// Function for when the player presses 'A'
void moveLeft(t_mlx *mlx, int x, int y)
{
	if (mlx->jeu->map[x][y - 1] != 'W') {
		if (mlx->jeu->map[x][y - 1] == 'C') {
			(mlx->left_items)--;
			mlx->jeu->map[x][y - 1] = 'G';
		}
		mlx->jeu->map[x][y] = 'G';
		(y)--;
		mlx->jeu->map[x][y] = 'P';
	}
	(mlx->count_mouvement)++;
}

// Function for when the player presses 'S'
void moveDown(t_mlx *mlx, int x, int y)
{
	if (mlx->jeu->map[x + 1][y] != 'W') {
		if (mlx->jeu->map[x + 1][y] == 'C') {
			(mlx->left_items)--;
			mlx->jeu->map[x + 1][y] = 'G';
		}
		mlx->jeu->map[x][y] = 'G';
		(x)++;
		mlx->jeu->map[x][y] = 'P';
	}
	(mlx->count_mouvement)++;
}

// Function for when the player presses 'D'
void moveRight(t_mlx *mlx, int x, int y)
{
	if (mlx->jeu->map[x][y + 1] != 'W') {
		if (mlx->jeu->map[x][y + 1] == 'C') {
			(mlx->left_items)--;
			mlx->jeu->map[x][y + 1] = 'G';
		}
		mlx->jeu->map[x][y] = 'G';
		(y)++;
		mlx->jeu->map[x][y] = 'P';
	}
	(mlx->count_mouvement)++;
}
