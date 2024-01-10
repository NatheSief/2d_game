#include <stdio.h>
#include <stdbool.h>
#include "../includes/so_long.h"

int estDansLaGrille(int x, int y, int lignes, int culumns)
{
    if (x >= 0 && x <= lignes && y >= 0 && y <= culumns)
		return (1);
	return (0);
}


int main() 
{
    int startX = -1, startY = -1;

    // Trouver les coordonnées de départ (P)
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (map[i][j] == 'P') {
                startX = i;
                startY = j;
                break;
            }
        }
    }

    if (startX != -1 && startY != -1 && dfs(map, startX, startY)) {
        printf("Il est possible d'aller de P à E sans passer par une case 1.\n");
    } else {
        printf("Il n'est pas possible d'aller de P à E sans passer par une case 1.\n");
    }

    return 0;
}
