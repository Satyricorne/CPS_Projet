#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "lecture_ecriture.h"
#include "convert_fct.h"


void transform(FILE * file, int optionG, int optionB, char * nom_fichier){
	Image img = malloc(sizeof(Image));
	if(file == NULL){					// Si on a pas de nom de fichier 
		lecture_std(img);				// On passe par l'entré standard
		nom_fichier = "./Image.ppm";	// Et on donne comme nom d'image Image.ppm par default
	}else{
		lire(img, file);				// Si on a un fichier en parametre alors on va le lire pour en ressortir img avec toute les données
	}
	Image sortie = malloc(sizeof(Image));
	if (img->type == P3 && optionG)		// Si on a l'option "-g" 
	{	
		sortie = gris(img, 0.299, 0.587, 0.114);	// On le transforme en nuance de gris
		ecrire(sortie, nom_fichier);				// Et on l'ecris dans un fichier
	}
	if (img->type == P3 && optionB)		// Si on a l'option "-b"
	{
		sortie = noir(img, 0.5);			// On le transforme en noir et blanc
		ecrire(sortie, nom_fichier);		// Et on l'ecrit dans le fichier
	}
}

void argument(int nb_arg, char *args[], int *optionG, int *optionB, FILE **fichier, char * nom_fichier[]){
	char retest_fichier[100];
	for (int i = 1; i < nb_arg; ++i)	// On regarde tout les parametre
	{
		printf("argv[%d] = %s\n", i, args[i]);	
		if (!strcmp(args[i],"-g"))				// Si c'est "-g"
		{
			*optionG = 1;						// On met le boolean associé a "true"
		} else if(!strcmp(args[i],"-b")){		// Si c'est "-b" 
			*optionB = 1;						// On met le boolean associé a "true"
		} else {								// Si c'est autre chose
			*fichier = fopen(args[i], "r");		// On considere que c'est le nom de fichier et on tente de l'ouvrir
			while (*fichier == NULL)			// Si on ne réussis pas
			{
				printf("Le fichier entré n'est pas disponible, saisissez en un autre : ");
				scanf("%s", retest_fichier);			// On demande de siaisir un fichier valide 
				*fichier = fopen(retest_fichier, "r");	// Et on retente de l'ouvrir
			}
			*nom_fichier = args[i];				// Et on met son nom dans la variable nom_fichier
		}
	}
}

int main(int argc, char *argv[]) {
	int optionG = 0, optionB = 0;	// Deux boolean qui seront mis a 1 si le parametre est present dans la commande
	char *nom_fichier;
	FILE * fichier = NULL;
	argument(argc, argv, &optionG, &optionB, &fichier, &nom_fichier);	//On analyse les parametre
	if(argc < 2){														// Il faut au moins un argument sinon la commande n'a pas de sens
	  printf("Problème d'argument vous devez saisir l'option et/ou le fichier à modifier");
	}else{
	  transform(fichier, optionG, optionB, nom_fichier);				// Tout est bon alors on lance la transformation
	}
}
