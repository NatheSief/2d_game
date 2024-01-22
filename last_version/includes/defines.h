/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:58:00 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/22 15:10:42 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFLONG_H
# define DEFLONG_H

//	DEFINES
# define TEXTS game->mlx->texts
# define MAP game->map->map

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

typedef struct s_info
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
	int			last_mouvement;
	int			left_items;
	t_count		*info;
	t_point		*dimensions;
	t_point		*player;
} t_info;

typedef struct s_map
{
	char	*name;
	char	**map;
	t_info	*info;
} t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_texture	*texts;
} t_mlx;

typedef struct s_game
{
	t_mlx	*mlx;
	t_map	*map;
} t_game;

#endif