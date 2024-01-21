/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:16:49 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/19 16:03:22 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	put_to_window(t_game *game, int i, int j)
{
	if (MAPS->map[i][j] == 'C')
		mlx_put_image_to_window(MLX, WIND, T_COLLECTIBLE, i * RES, j * RES);
	else if (MAPS->map[i][j] == 'E')
		mlx_put_image_to_window(MLX, WIND, T_EXIT, i * RES, j * RES);
	else if (MAPS->map[i][j] == 'G')
		mlx_put_image_to_window(MLX, WIND, T_GROUND, i * RES, j * RES);
	else if (MAPS->map[i][j] == 'P')
		mlx_put_image_to_window(MLX, WIND, T_PLAYER, i * RES, j * RES);
	else if (MAPS->map[i][j] == 'W')
		mlx_put_image_to_window(MLX, WIND, T_WALL, i * RES, j * RES);
	
}

void	check_open(t_game *game)
{
	int fd1;
	int fd2;
	int fd3;
	int fd4;
	int fd5;
		
	fd1 = open(T_COLLECTIBLE, O_RDONLY);
	fd2 = open(T_COLLECTIBLE, O_RDONLY);
	fd3 = open(T_COLLECTIBLE, O_RDONLY);
	fd4 = open(T_COLLECTIBLE, O_RDONLY);
	fd5 = open(T_COLLECTIBLE, O_RDONLY);
	if (fd1 == -1 || fd2 == -1 || fd3 == -1 || fd4 == -1 || fd5 == -1)
		ft_error_free("We can't open .XPM files bitch !", game);
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	close(fd5);
}

void	free_lines(char **str, int i)
{
	int	j;

	j = -1;
	while (++j <= i)
		free(str[i]);
}

void cpy_map(char **original, t_game *game, t_game *cpy)
{
	int		i;

	cpy->map->map = malloc(sizeof(char *) * WIDTH);
	if (!cpy->map->map)
	{
		free(cpy->map->map);
		return;
	}
	i = -1;
	while (++i < WIDTH)
	{
		cpy->map->map[i] = malloc (sizeof(char) * LENGHT);
		if (!cpy->map->map[i])
		{
			free_lines(cpy->map->map, i);
			return;
		}
		cpy->map->map[i] = ft_strdup(original[i]);
	}
}

t_game	*copy_info(t_game *original)
{
	t_game	*game;

	game = init_game();
	cpy_map(original->map->map, original, game);
	INFO->count = cpy_info();
	if (!MAPS->map || !INFO->count)
		ft_error_free("Problem occuring when copping the map ! \n", game);
	return (game);
}
