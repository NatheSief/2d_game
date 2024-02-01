/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:41:09 by nsiefert          #+#    #+#             */
/*   Updated: 2024/01/27 11:19:14 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

static char	*ft_next(char **temp)
{
	char	*line;
	char	*ptr;

	ptr = *temp;
	while (*ptr && *ptr != '\n')
		++ptr;
	ptr += (*ptr == '\n');
	line = ft_substr (*temp, 0, (size_t)(ptr - *temp));
	if (!line)
	{
		free (*temp);
		return (NULL);
	}
	ptr = ft_substr (ptr, 0, ft_strlen (ptr));
	free (*temp);
	*temp = ptr;
	return (line);
}

// Fonction qui permet de lire une ligne en entier en s'arretant a \0 et \n
// la variable r me permet de stopper en cas de fin de fichier et strchr en cas
// de \n .
static char	*ft_read(char *temp, int fd, char *buf)
{
	ssize_t		r;

	r = 1;
	while (r && !ft_strchr (temp, '\n'))
	{
		r = read (fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			free (buf);
			free (temp);
			return (NULL);
		}
		buf[r] = 0;
		temp = ft_strjoin_free_s1 (temp, buf);
		if (!temp)
		{
			free (buf);
			return (NULL);
		}
	}
	free (buf);
	return (temp);
}

// Fonction qui permet de lire la ligne du fichier en la stockant dans une
// ligne d'un double tableau pour permettre la lecture de plusieurs fichiers
// en meme temps
char	*get_next_line(int fd)
{
	static char	*temp[OPEN_MAX];
	char		*buf;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	if (!temp[fd])
		temp[fd] = ft_strdup("");
	if (!temp[fd])
		return (NULL);
	buf = malloc (sizeof (*buf) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free (temp[fd]);
		return (NULL);
	}
	temp[fd] = ft_read (temp[fd], fd, buf);
	if (!temp[fd])
		return (free(temp[fd]), NULL);
	if (!*temp[fd])
	{
		free (temp[fd]);
		temp[fd] = NULL;
		return (NULL);
	}
	return (ft_next(&temp[fd]));
}

// #include <stdio.h>
// int    main(int ac, char **av)
// {
//     int        fd;
//     int        fd2;
//     int        fd3;
//     char    *str;
//     char    *str2;
//     char    *str3;

//     fd = open(av[1], O_RDONLY);
// 	printf ("fd du premier fichier : %d\n", fd);
//     fd2 = open(av[2], O_RDONLY);
// 	printf ("fd du deuxieme fichier : %d\n", fd2);
//     fd3 = open(av[3], O_RDONLY);
// 	printf ("fd du troisieme fichier : %d\n", fd3);
//     (void) ac;
//     str = get_next_line(fd);
//     str2 = get_next_line(fd2);
//     str3 = get_next_line(fd3);
//     while (str && str2 && str3)
//     {
//         printf("%s", str);
//         printf("%s", str2);
//         printf("%s", str3);
//         free(str);
//         free(str2);
//         free(str3);
//         str = get_next_line(fd);
//         str2 = get_next_line(fd2);
//         str3 = get_next_line(fd3);
//     }
//     return (0);
// }
