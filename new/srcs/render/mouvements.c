/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:54:19 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/17 18:59:15 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Function for when the player presses 'W'
void moveUp(t_game *game, int x, int y)
{
	if (MAPS->map[x - 1][y] != 'W') 
	{
		if (MAPS->map[x - 1][y] == 'C') 
		{
			INFO->coll_left--;
			MAPS->map[x - 1][y] = 'G';
		}
		else if (MAPS->map[x - 1][y] == 'E')
		{
			if (INFO->coll_left == 0)
				end_game(game);
			return ;
		}
		if (1 == 1) 
		{
			MAPS->map[x][y] = 'G';
			(x)--;
			MAPS->map[x][y] = 'P';
		}
		INFO->last_movement = 1;
	}
	INFO->movement_count++;
	PLAYER_P->x = x;
	PLAYER_P->y = y;
}

// Function for when the player presses 'A'
void moveLeft(t_game *game, int x, int y)
{
	if (MAPS->map[x][y - 1] != 'W') 
	{
		if (MAPS->map[x][y - 1] == 'C') 
		{
			INFO->coll_left--;
			MAPS->map[x][y - 1] = 'G';
		}
		else if (MAPS->map[x][y - 1] == 'E')
		{
			if (INFO->coll_left == 0)
				end_game(game);
			return ;
		}
		else 
		{
			MAPS->map[x][y] = 'G';
			(y)--;
			MAPS->map[x][y] = 'P';
		}
		INFO->last_movement = 2;
	}
	INFO->movement_count++;
	PLAYER_P->x = x;
	PLAYER_P->y = y;
}

// Function for when the player presses 'S'
void moveDown(t_game *game, int x, int y)
{
	if (MAPS->map[x + 1][y] != 'W') 
	{
		if (MAPS->map[x + 1][y] == 'C') 
		{
			INFO->coll_left--;
			MAPS->map[x + 1][y] = 'G';
		}
		else if (MAPS->map[x + 1][y] == 'E')
		{
			if (INFO->coll_left == 0)
				end_game(game);
			return;
		}
		else 
		{
			MAPS->map[x][y] = 'G';
			(x)++;
			MAPS->map[x][y] = 'P';
		}
		INFO->last_movement = 3;
	}
	INFO->movement_count++;
	PLAYER_P->x = x;
	PLAYER_P->y = y;
}

// Function for when the player presses 'D'
void moveRight(t_game *game, int x, int y)
{
	if (MAPS->map[x][y + 1] != 'W') 
	{
		if (MAPS->map[x][y + 1] == 'C') 
		{
			(INFO->coll_left)--;
			MAPS->map[x][y + 1] = 'G';
		}
		else if (MAPS->map[x][y + 1] == 'E')
		{
			if (INFO->coll_left == 0)
				end_game(game);
			return ;
		}
		else
		{
		MAPS->map[x][y] = 'G';
		(y)++;
		MAPS->map[x][y] = 'P';
		}
		INFO->last_movement = 4;
	}	
	INFO->movement_count++;
	PLAYER_P->x = x;
	PLAYER_P->y = y;
}
