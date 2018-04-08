#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "main.h"
#include "couleur_fonction.h"

char * type_print(Type t){					//Fontion pour afficher le type en chaine de caractère
	switch(t){
		case P1 : return "P1";
		case P2 : return "P2";
		case P3 : return "P3";
		default : return NULL;
	}
}

void lecture_std(Image img){
	img->type = P3;							//Fonction de lecture dans l'entrée standard si il n'y a pas de fichier
	printf("Saisir la largeur : \n");		
	scanf("%i",&(img->largeur));			//On lit la largeur

	printf("Saisir la hauteur : \n");
	scanf("%i",&(img->hauteur));			//On lit la hauteur

	printf("Saisir la valeur maximal : \n");
	scanf("%i",&(img->val_max));			//On lit la valeur max
	img->data = malloc(sizeof(uint64_t)*img->largeur*img->hauteur);
	uint64_t r,g,b;

	for (int i = 0; i < img->hauteur; ++i){	//On lit toute les données de long en large
		for (int j = 0; j < img->largeur; ++j){
			printf("Pixel %d Ligne %d (R V B) : ", j+1,i+1);
			scanf("%lu %lu %lu",&r,&g,&b);
			*(img->data+i*img->largeur+j) = creer_pixel(r,g,b);
		}
	}
}

void lire(Image img, FILE * FileImage)
{
	char z;
	fscanf(FileImage, "%c%u\n", &z, &img->type);				// On lit le type et on stock 
	printf("Type entrée : %s\n", type_print(img->type));

	fscanf(FileImage, "%d %d\n", &img->largeur, &img->hauteur);	//On lit la hauteur et la largeur et on stock
	printf("Hauteur et Largeur valide : %dx%d\n", img->largeur, img->hauteur);

	fscanf(FileImage, "%d\n", &img->val_max);					// On lit la valeur max et on stock
	printf("Valeur max valide : %d\n", img->val_max);

	img->data = malloc(sizeof(uint64_t)*img->largeur*img->hauteur);
	uint64_t r, g, b;
	for (int i = 0; i < img->hauteur; ++i)						// On lit chaque valeur en parcourant de long en large
	{
		for (int j = 0; j < img->largeur; ++j)
		{
			fscanf(FileImage, "%lu %lu %lu\t", &r, &g, &b);
			*(img->data+i*img->largeur+j) = creer_pixel(r,g,b);
		}
	}
	printf("Data valide, premiere valeur : %lu %lu %lu ", (*(img->data))&MASKB, ((*(img->data))&MASKG)>>DECALG, ((*(img->data))&MASKR)>>DECALR);
	printf("et derniere valeur : %lu %lu %lu\n", (*(img->data+img->largeur*img->hauteur))&MASKB, ((*(img->data+img->largeur*img->hauteur))&MASKG)>>DECALG, ((*(img->data+img->largeur*img->hauteur))&MASKR)>>DECALR);
}

void ecrire(Image img, char * nomFichier){
	char * nomSortie = malloc(sizeof(char)*strlen(nomFichier));
	nomSortie = nomFichier;
	
	int i = 0;
	while(i < strlen(nomSortie)-3)
	{
		i++;
	}
	if (img->type == P2){
		if (!strcmp(nomFichier, "./Image.ppm"))		// Ici un bug incomprehensible fait que si on passe par l'entrée standard on a une erreur a la ligne nomSortie[i+1] = 'g';
		{
			nomSortie = "./Image.pgm";
		} else {
			nomSortie[i+1] = 'g';
		}
	}
	else if (img->type == P1) {
		if (!strcmp(nomFichier, "./Image.ppm"))		// meme bug qu'au dessus
		{
			nomSortie = "./Image.pbm";
		} else {
			nomSortie[i+1] = 'b';
		}
	}
	// jusqu'a la on ne faisait que nommée le fichier de sortie.

	FILE * fichier_cree = fopen(nomSortie, "w+");					// On ouvre le fichier et on ecrit dedans
	fprintf(fichier_cree, "%c%d\n", 'P', img->type);
	fprintf(fichier_cree, "%d %d\n", img->largeur, img->hauteur);
	if(img->type == P2)	fprintf(fichier_cree, "%d\n", img->val_max);
	for (int i = 0; i < img->hauteur; ++i)
	{
		for (int j = 0; j < img->largeur; ++j)
		{
			fprintf(fichier_cree, "%lu ", *(img->data+i*img->largeur+j));
		}
		fprintf(fichier_cree, "\n");
	}
}
