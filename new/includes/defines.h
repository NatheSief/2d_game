/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:01:58 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/18 17:07:23 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_SLONG_H
# define DEFINES_SLONG_H

// INCLUDES
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"

// TEXTURES PATHS
# define COLLECTIBLE_PATH 	"./textures/collectible.xpm"
# define EXIT_PATH			"./textures/exit.xpm"
# define GROUND_PATH		"./textures/ground.xpm"
# define PLAYER_PATH		"./textures/player.xpm"
# define WALL_PATH			"./textures/wall.xpm"

// STRUCTURE PATHS

# define TRASH				game->collector.next

//		DIMENSIONS
# define LENGHT				game->info->lenght
# define WIDTH				game->info->width

//		TEXTURES_PATH
# define IMAGES				game->mlx->img
# define T_COLLECTIBLE		game->mlx->img->t_coll
# define T_EXIT				game->mlx->img->t_exit
# define T_GROUND			game->mlx->img->t_ground
# define T_PLAYER			game->mlx->img->t_player
# define T_WALL				game->mlx->img->t_wall

//		COUNT ELEMENT PATH
# define COUNT				game->info->count
# define C_COLLECTIBLE		game->info->count->count_coll
# define C_EXIT				game->info->count->count_exit
# define C_GROUND			game->info->count->count_ground
# define C_PLAYER			game->info->count->count_player
# define C_WALL				game->info->count->count_wall

//		SHORT PATHS
# define MAPS				game->map
# define INFO				game->info
# define PLAYER_P			game->info->player_pos

//		MLX SHORTCUTS
# define MLX 				game->mlx->mlx
# define WIND				game->mlx->win
// RESOLUTION DEFINITION
# define RES				64

// STRUCTURES POUR LE JEU 
//		STRUCTURES MINEURES
typedef struct s_point
{
	int		x;
	int		y;
} t_point;

typedef struct s_count
{
	int		count_coll;
	int		count_exit;
	int		count_ground;
	int		count_player;
	int		count_wall;
} t_count;

typedef struct s_text
{
	void	*t_coll;
	void	*t_exit;
	void	*t_ground;
	void	*t_player;
	void	*t_wall;
} t_text;

//		STRUCTURES MAJEURES
typedef struct s_map
{
	char	*name;
	char	**map;
} t_map;

typedef	struct s_mlx
{
	void	*mlx;
	void	*win;
	t_text	*img;
} t_mlx;

typedef struct s_info
{
	int		coll_left;
	int		last_movement;
	int		lenght;
	int		movement_count;
	int		width;
	t_count	*count;
	t_point	*player_pos;
} t_info;

// STRUCTURE GENERALE
typedef struct s_game
{
	t_mlx		*mlx;
	t_map		*map;
	t_info		*info;
} t_game;

#endif