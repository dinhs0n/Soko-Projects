#include "sokoban.h"
#include <stdio.h>


int main(int argc, char ** argv) {

	Position position;

	Grille initiale = {
 "########################",
 "#.........#......#.....#",
 "##.....O###............#",
 "###.............O#.....#",
 "####.............#O....#",
 "##################.....#",
 "####.............#.....#",
 "###...............O..###",
 "##...........#########o#",
 "#...S................oo#",
 "#.....................o#",
 "########################"
};
	Grille nouvelle;
	Boolean condition = true;
	
/*	position = getSokoban(initiale);
	printf("Voici ma position : { %d, %d }\n", position.colonne, position.ligne);
	if(position.colonne == 0 && position.ligne == 0) {
		error(NO_SOKOBAN);
	}
	else {

		afficheGrille(initiale);
	}

*/

	nouveauJeu(initiale, nouvelle);

	position = getSokoban(nouvelle);

	printf("hauteur = %d , largeur = %d\n", position.colonne, position.ligne);

	position = newPosition(position, HAUT);

	printf("hauteur = %d , largeur = %d\n", position.colonne, position.ligne);

/*	while(condition == true) {
		
		afficheGrille(nouvelle);
		printf("> ");
		char commande[MAXCH+1];
		if(fgets(commande,MAXCH,stdin) == NULL ) {
			error(BAD_ENTRY);
		}
		printf("%s\n", commande);
	}
*/
	return 0;
}

