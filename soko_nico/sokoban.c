#include "sokoban.h"
#include <stdio.h>
#include <stdlib.h>

void afficheGrille(Grille grille)
{
	int j;
	int i;
	printf("\n");

	for(i=0; i < HAUTEUR; i++) {
		for(j = 0; j < LARGEUR + 1; j++) {
			printf("%c", grille[i][j]);
		}
		printf("\n");
	}
} 

Position getSokoban(Grille grille)
{
	int j;
	int i;
	Boolean test = false;
	Position position;

	for(i=0; i < HAUTEUR; i++) {
		for(j = 0; j < LARGEUR + 1; j++) {
			if(grille[i][j] == SOKOBAN) {
				position.ligne = j;
				position.colonne = i;
				test = true;
			}
		}
	}
	if(test == false) 
	{
			position.ligne = 0;
			position.colonne = 0;
	}
	
	return position;

} 

 void error(CodeError code)
  {
    switch (code) {
     case NO_SOKOBAN : fprintf(stderr,"pas de Sokoban!\n"); break;
     case INCORRECT_GRID : fprintf(stderr,"Grille initiale incorrecte !\n"); break;
     default: fprintf(stderr,"code erreur inconnu!\n");
    }
    exit(code);
  }/*error*/

void nouveauJeu(Grille init, Grille g) {
	
	int j;
	int i;	

	
	if(verifGrille(init) == false) error(INCORRECT_GRID);

	for(i=0; i < HAUTEUR; i++) {
		for(j = 0; j < LARGEUR + 1 ; j++) {
			g[i][j] = init[i][j];
		}
	}
	
	for(i=0; i < HAUTEUR; i++) {
		for(j = 0; j < LARGEUR + 1 ; j++) {
			if(init[i][j] == CAISSE || init[i][j] == SOKOBAN) {
				init[i][j] = VIDE;
			}
		}
	}
}

/*TODO*/
Boolean verifGrille(Grille g) {

	int i; int j; int largeur;
	int nbCaisse = compteGrille(g, CAISSE);
	int nbCible = compteGrille(g, CIBLE);

	if(nbCaisse < 1) return false;
	if(nbCaisse != nbCible) return false;

	for(i=0; i<HAUTEUR; i++) {
		largeur = 0;
		for(j = 0; g[i][j] != '\0'; j++) {
			largeur=largeur+1;
			
		}
		if(largeur != LARGEUR ) return false;
	}
	return true;	
}

int compteGrille(Grille g, char c) {

	int j;
	int i;
	int compteur = 0;

	for(i=0; i < HAUTEUR; i++) {
		for(j = 0; j < LARGEUR + 1; j++) {
			if(g[i][j] == c) {
				compteur = compteur + 1;
			}
		}
	}

	return compteur;

}