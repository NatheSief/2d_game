/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:05:39 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/22 14:47:17 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SLONG_H
# define SLONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"

# define WALL_PATH "./textures/wall.xpm"
# define COLLECTIBLE_PATH "./textures/collectible.xpm"
# define GROUND_PATH "./textures/ground.xpm"
# define PLAYER_PATH "./textures/player.xpm"
# define EXIT_PATH "./textures/door.xpm"

# define RES 64

typedef struct s_texture
{
	void *t_wall;
    void *t_ground;
    void *t_player;
    void *t_exit;
    void *t_collectible;
} t_texture;

typedef struct s_dimensions
{
	int		lenght;
	int		width;
} t_dimensions;

typedef struct s_point
{
	int		x;
	int		y;
} t_point;

typedef struct s_count
{
	int exit;
	int	player;
	int collectibles;
	int	wall;
	int	ground;
} t_count;


// Structure globale de la map
typedef struct s_map
{
	char			*name;
	char 			**map;
	t_dimensions	*dimensions;
	t_point			*player;
	t_point			*exit;
	t_count			*info;
} t_map;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_texture	*map;
	
	int			count_mouvement;
	int			left_items;
	int			last_movement;
	t_map		*jeu;
} t_mlx;

// Prototypes
// -- Init mes structures --
t_map	*init_map(void);
t_mlx	*init_mlx(void);
// -- Error --
void 	ft_error_print(char *str);
void	ft_error(char *str, t_map *map);
void	ft_error_mlx(char *str, t_mlx *mlx);
void 	ft_end_game(t_mlx *mlx);
void	ft_free_mlx(t_mlx *mlx);
void	ft_free_text(t_mlx *mlx);
void	ft_free_map(t_map *map);

// -- Parsing --
void	check_parse(t_map *map);
void	check_map(char *str, t_map *map);
void	launch_game(t_mlx *mlx);
void	check_path(t_map *map);
void	dfs(t_map *map, int i, int j);
char 	**char_tab_dup(t_map *map, t_map *new_map);
void	init_map_info(t_count *map_info);
void	check_map_info(t_map *map);
void 	libere(char **elem);

// -- Utils--
void	remake(t_map *map);
void 	put_to_up(t_map *game);

// -- Mouvements --
void	evolve_display(t_mlx *mlx, int x, int y);
void 	moveUp(t_mlx *mlx, int x, int y);
void 	moveLeft(t_mlx *mlx, int x, int y);
void 	moveDown(t_mlx *mlx, int x, int y);
void 	moveRight(t_mlx *mlx, int x, int y);

#endif