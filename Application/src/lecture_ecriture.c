#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "main.h"
#include "couleur_fonction.h"

char * type_print(Type t){
	switch(t){
		case P1 : return "P1";
		case P2 : return "P2";
		case P3 : return "P3";
		default : return NULL;
	}
}

void afficher_bit(uint64_t a){
	// Attention l'affichage est inversé bit a bit !
	for (int i = 0; i < 64; ++i)
	{
		if (i==16 || i == 32 || i == 48)
		{
			printf(" ");
		}
		if(a%2){
			printf("1");
			a/=2;
		}
		else{
			printf("0");
			a/=2;
		}
	}
	printf("\n");

}

void lecture_std(Image img){
	img->type = P3;
	printf("Saisir la largeur : \n");
	scanf("%i",&(img->largeur));

	printf("Saisir la hauteur : \n");
	scanf("%i",&(img->hauteur));

	printf("Saisir la valeur maximal : \n");
	scanf("%i",&(img->val_max));

	uint64_t r,g,b;

	for (int i = 0; i < img->hauteur; ++i){
		for (int j = 0; j < img->largeur; ++j){
			printf("Pixel %d Ligne %d", j+1,i+1);
			scanf("%lu %lu %lu",&r,&g,&b);
			*(img->data+i*img->largeur+j) = creer_pixel(r,g,b);
		}
	}

}

void lire(Image img, FILE * FileImage)
{
	char z;
	fscanf(FileImage, "%c%u\n", &z, &img->type);
	printf("Type entrée : %s\n", type_print(img->type));

	fscanf(FileImage, "%d %d\n", &img->largeur, &img->hauteur);
	printf("Hauteur et Largeur valide : %dx%d\n", img->largeur, img->hauteur);

	fscanf(FileImage, "%d\n", &img->val_max);
	printf("Valeur max valide : %d\n", img->val_max);

	img->data = malloc(sizeof(uint64_t)*img->largeur*img->hauteur);
	uint64_t r, g, b;
	for (int i = 0; i < img->hauteur; ++i)
	{
		for (int j = 0; j < img->largeur; ++j)
		{
			fscanf(FileImage, "%lu %lu %lu\t", &r, &g, &b);
			*(img->data+i*img->largeur+j) = creer_pixel(r,g,b);
		}
	}
	printf("Data valide, premiere valeur : %lu %lu %lu ", (*(img->data))&MASKB, ((*(img->data))&MASKG)>>DECALG, ((*(img->data))&MASKR)>>DECALR);
	printf("et derniere valeur : %lu %lu %lu\n", (*(img->data+img->largeur*img->hauteur))&MASKB, ((*(img->data+img->largeur*img->hauteur))&MASKG)>>DECALG, ((*(img->data+img->largeur*img->hauteur))&MASKR)>>DECALR);
	//Affichage des DATA
	/*for (int i = 0; i < img->hauteur; ++i)
	{
		for (int j = 0; j < img->largeur; ++j)
		{
			printf("%lu %lu %lu\t", *(img->data+i*img->largeur+j)&maska, (*(img->data+i*img->largeur+j)&maskb)>>16, (*(img->data+i*img->largeur+j)&maskc)>>32);
		}
		printf("\n");
	}*/
}

void ecrire(Image img, char * nomFichier){
	char * nomSortie = nomFichier;
	int i = 0;
	while(i < strlen(nomSortie)-3)
	{
		i++;
	}
	if (img->type == P2)
		nomSortie[i+1] = 'g';
	else if (img->type == P1) nomSortie[i+1] = 'b';


	FILE * fichier_cree = fopen(nomSortie, "w+");
	fprintf(fichier_cree, "%c%d\n", 'P', img->type);
	fprintf(fichier_cree, "%d %d\n", img->largeur, img->hauteur);
	if(img->type == P2)	fprintf(fichier_cree, "%d\n", img->val_max);
	for (int i = 0; i < img->hauteur; ++i)
	{
		for (int j = 0; j < img->largeur; ++j)
		{
			//printf("%c %lu\n", *(img->data+i*img->largeur+j), *(img->data+i*img->largeur+j));
			fprintf(fichier_cree, "%lu ", *(img->data+i*img->largeur+j));
		}
		fprintf(fichier_cree, "\n");
	}
}
