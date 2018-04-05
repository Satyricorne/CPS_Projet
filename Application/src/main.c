#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "lecture_ecriture.h"
#include "convert_fct.h"


void transform(FILE * file, int optionG, int optionB){
	Image img = malloc(sizeof(Image));
	if(file == NULL){
		ecrire_std(img);
	}else{
		lire(img, file);
	}
	Image sortie = malloc(sizeof(Image));
	if (img->type == P3 && optionG){
		sortie = gris(img, 0.299, 0.587, 0.114);
		ecrire(sortie, file);
	}
	if (img->type == P3 && optionB)
	{
		sortie = noir(img, 0.5);
		ecrire(sortie, file);
	}
}

argument( int nb_arg, char *args[], int optionG, int optionB, FILE *fichier){
	char nom_fichier[100];
	for (int i = 1; i < nb_arg; ++i)
	{
		printf("argv[%d] = %s\n", i, args[i]);
		if (!strcmp(args[i],"-g"))
		{
			optionG = 1;
		} else if(!strcmp(args[i],"-b")){
			optionB = 1;
		} else {
			fichier = fopen(argv[i], "r");
			while (fichier == NULL)
			{
				printf("Le fichier entré n'est pas disponible, saisissez en un autre : ");
				scanf("%s", nom_fichier);
				fichier = fopen(nom_fichier, "r");
			}
		}
	}
}

int main(int argc, char *argv[]) {
	int optionG = 0, optionB = 0;
	FILE * fichier;
	argument(argc, argv, optionG, optionB, fichier);
	if(argc != 3){
	  printf("Problème d'argument vous devez saisir l'executable, l'option et le fichier à modifier");
	}else{
	  transform(fichier, optionG, optionB);
	}
}
