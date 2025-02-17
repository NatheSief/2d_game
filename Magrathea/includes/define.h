/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:18:43 by nsiefert          #+#    #+#             */
/*   Updated: 2024/02/01 14:34:48 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

// DEFINE PART

//	ENUM

enum e_race
{
	human		=	0,
	elf			=	1,
	dwarf		=	2,
	dragonborn	=	3
};

//	STRUCTS

//	Coordonnes x et y
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

// Liste chainee qui contient tous mes pointeurs sur les textures
typedef struct s_text
{
	char			*name;
	void			*t_bloc;
	struct s_text	*next;
}	t_text;

// Structure contenant mes infos en lien avec la MLX
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_text	**textures;
}	t_mlx;

typedef struct s_stats
{
	int	force;
	int	dexterite;
	int	constitution;
	int	inteligence;
	int	sagesse;
	int	charisme;
}	t_stats;

typedef struct s_mob
{
	e_race	race;
	char	**name;
	
} t_mob;

// Structure contenant toutes les infos de chacun de mes PNJ's
typedef struct s_pnj
{
	int				id;				// Permet de retrouver qui est qui plus facilement
	t_point			*position;		// Pratique pour le systeme de combat/interaction
	char			*race;			// Permet de trouver les desgins associes et les caracteristiques du perso
	int				*appreciation;	// L'image qu'il a du joueur (en fonction de ses actions), si elle est proche de -10 il commencera a etre violent envers le perso
	t_stats			*stats;			// Stats du PNJ
	int 			alignement;		// 0 = neutre, plus c'est proche de 10 c'est bon et plus c'est proche de -10 c'est mauvais
	struct s_pnj	*next;			// Pointeur vers le PNJ suivant
}	t_pnj;

// Contient toutes els infos de la map
typedef struct s_info
{
	t_point	*dimensions;
	t_point	*player;
}	t_info;

// Structure de la map qui contient les infos de toute la map
typedef struct s_map
{
	t_info	*info;
	char	***map;
	char	*name;	
}	t_map;

// Structure generale du jeu
typedef struct s_game
{
	t_mlx		*mlx; // infos MLX
	t_map		*map; // infos map
}	t_game;

#endif