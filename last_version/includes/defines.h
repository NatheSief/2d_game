/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:58:00 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/23 18:50:42 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFLONG_H
# define DEFLONG_H

//	DEFINES
# define MAP	game->map
# define MLX	game->mlx

# define TEXTS	game->mlx->texts
# define MAPS	game->map->map

# define LENGHT	MAP->info->dimensions.y
# define WIDTH	MAP->info->dimensions.x

# define COLL_PATH "./texts/texture_coll.xpm"
# define EXIT_PATH "./texts/texture_exit.xpm"
# define GROUND_PATH "./texts/texture_ground.xpm"
# define PLAYER_PATH "./texts/texture_player.xpm"
# define WALL_PATH "./texts/texture_wall.xpm"

# define T_COLL MLX->texts->t_collectibles
# define T_EXIT MLX->texts->t_exit
# define T_GROUND MLX->texts->t_ground
# define T_PLAYER MLX->texts->t_player
# define T_WALL MLX->texts->t_wall

# define RES 64
//	STRUCTURES 
typedef struct s_texture
{
	void	*t_collectibles;
	void	*t_exit;
	void	*t_ground;
	void	*t_player;
	void	*t_wall;
} t_texture;

typedef struct s_point
{
	int	x;
	int	y;
} t_point;

typedef struct s_count
{
	int	c_collectibles;
	int	c_exit;
	int	c_ground;
	int	c_player;
	int	c_wall;
} t_count;

typedef struct s_info
{
	int			count_mouvements;
	t_point		dimensions;
	t_count		*info;
	int			last_mouvement;
	int			left_items;
	t_point		player;
} t_info;

typedef struct s_map
{
	t_info	*info;
	char	**map;
	char	*name;
} t_map;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_texture	*texts;
} t_mlx;

typedef struct s_game
{
	t_map	*map;
	t_mlx	*mlx;
} t_game;

#endif