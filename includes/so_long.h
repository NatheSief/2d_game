#ifndef SLONG_H
# define SLONG_H

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/include/libft.h"

typedef struct s_texture
{
	void *t_wall;
    void *t_ground;
    void *t_player;
    void *t_exit;
    void *t_collectible;
} t_texture;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	int			count_mouvement;
	t_texture	*map;
} t_mlx;

typedef struct s_dimensions
{
	int		lenght;
	int		width;
} t_dimesions;

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
	char		*name;
	char 		**map;
	t_dimesions	*dimensions;
	t_point		*player;
	t_point		*exit;
	t_count		*info;
} t_map;

// Prototypes
// -- Error --
void 	ft_error_print(char *str);
void	ft_error(char *str, t_map *map);
// -- Parsing --
void	*check_parse(t_map *map);

#endif