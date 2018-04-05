#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "lecture_ecriture.h"
#include "convert_fct.h"


void transform(FILE * file, int optionG, int optionB, char * nom_fichier){
	Image img = malloc(sizeof(Image));
	if(file == NULL){
		lecture_std(img);
		nom_fichier = "./Image.ppm";
	}else{
		lire(img, file);
	}
	Image sortie = malloc(sizeof(Image));
	if (img->type == P3 && optionG){
		sortie = gris(img, 0.299, 0.587, 0.114);
		ecrire(sortie, nom_fichier);
	}
	if (img->type == P3 && optionB)
	{
		sortie = noir(img, 0.5);
		ecrire(sortie, nom_fichier);
	}
}

void argument(int nb_arg, char *args[], int *optionG, int *optionB, FILE **fichier, char * nom_fichier[]){
	char retest_fichier[100];
	for (int i = 1; i < nb_arg; ++i)
	{
		printf("argv[%d] = %s\n", i, args[i]);
		if (!strcmp(args[i],"-g"))
		{
			*optionG = 1;
		} else if(!strcmp(args[i],"-b")){
			*optionB = 1;
		} else {
			*fichier = fopen(args[i], "r");
			while (*fichier == NULL)
			{
				printf("Le fichier entré n'est pas disponible, saisissez en un autre : ");
				scanf("%s", retest_fichier);
				*fichier = fopen(retest_fichier, "r");
			}
			*nom_fichier = args[i];
		}
	}
}

int main(int argc, char *argv[]) {
	int optionG = 0, optionB = 0;
	char *nom_fichier;
	FILE * fichier;
	argument(argc, argv, &optionG, &optionB, &fichier, &nom_fichier);
	if(argc < 2){
	  printf("Problème d'argument vous devez saisir l'option et/ou le fichier à modifier");
	}else{
	  transform(fichier, optionG, optionB, nom_fichier);
	}
}
