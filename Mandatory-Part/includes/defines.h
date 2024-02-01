/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:58:00 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/25 13:24:42 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

//	DEFINES
# define MAP	game->map
# define MLX	game->mlx

# define TEXTS	game->mlx->texts
# define MAPS	game->map->map

# define LENGHT	MAP->info->dimensions->y
# define WIDTH	MAP->info->dimensions->x
# define PLAYER MAP->info->player

# define INFO MAP->info->info

# define COLL_PATH "./textures/collectible.xpm"
# define EXIT_PATH "./textures/exit.xpm"
# define GROUND_PATH "./textures/ground.xpm"
# define PLAYER_PATH "./textures/player.xpm"
# define WALL_PATH "./textures/wall.xpm"

# define T_COLL MLX->texts->t_collectibles
# define T_EXIT MLX->texts->t_exit
# define T_GROUND MLX->texts->t_ground
# define T_PLAYER MLX->texts->t_player
# define T_WALL MLX->texts->t_wall

# define RES 64

# define MLX_nw mlx_new_window
//	STRUCTURES 
typedef struct s_texture
{
	void	*t_collectibles;
	void	*t_exit;
	void	*t_ground;
	void	*t_player;
	void	*t_wall;
}	t_texture;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_count
{
	int	c_collectibles;
	int	c_exit;
	int	c_ground;
	int	c_player;
	int	c_wall;
}	t_count;

typedef struct s_info
{
	int			count_mouvements;
	t_point		*dimensions;
	t_count		*info;
	int			last_mouvement;
	int			left_items;
	t_point		player;
}	t_info;

typedef struct s_map
{
	t_info	*info;
	char	**map;
	char	*name;
}	t_map;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_texture	*texts;
}	t_mlx;

typedef struct s_game
{
	t_map	*map;
	t_mlx	*mlx;
}	t_game;

#endif