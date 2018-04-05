#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#include "../headers/main.h"

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
	uint64_t a, b, c, maska = 0xFFFF, maskb = 0xFFFF0000, maskc = 0xFFFF00000000;
	for (int i = 0; i < img->hauteur; ++i)
	{
		for (int j = 0; j < img->largeur; ++j)
		{
			fscanf(FileImage, "%lu %lu %lu\t", &a, &b, &c);
			a = a & maska;
			b = b << 16;
			b = b & maskb;
			c = c << 32;
			c = c & maskc;
			*(img->data+i*img->largeur+j) = a+b+c;
		}
	}
	printf("Data valide, premiere valeur : %lu %lu %lu ", (*(img->data))&maska, ((*(img->data))&maskb)>>16, ((*(img->data))&maskc)>>32);
	printf("et derniere valeur : %lu %lu %lu\n", (*(img->data+img->largeur*img->hauteur))&maska, ((*(img->data+img->largeur*img->hauteur))&maskb)>>16, ((*(img->data+img->largeur*img->hauteur))&maskc)>>32);
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


Image gris(Image img, float a, float b, float c){
	Image res = malloc(sizeof(Image));
	res->type = P2;
	res->largeur = img->largeur;
	res->hauteur = img->hauteur;
	res->val_max = img->val_max;
	uint64_t maska = 0xFFFF, maskb = 0xFFFF0000, maskc = 0xFFFF00000000;
	res->data = malloc(sizeof(uint64_t)*res->largeur*res->hauteur);
	for (int i = 0; i < res->hauteur; ++i)
	{
		for (int j = 0; j < res->largeur; ++j)
		{

			uint64_t rouge = a*((*(img->data+i*img->largeur+j))&maska);
			uint64_t vert = b*(((*(img->data+i*img->largeur+j))&maskb)>>16);
			uint64_t bleu = c*(((*(img->data+i*img->largeur+j))&maskc)>>32);
			*(res->data+i*res->largeur+j) = rouge + vert + bleu;

			//printf("%lu\n", *(res->data+i*res->largeur+j));
		}
	}
	return res;
}

Image noir(Image img, float alpha){
	int cond;
	Image res = malloc(sizeof(Image));
	res->type = P1;
	res->largeur = img->largeur;
	res->hauteur = img->hauteur;
	res->val_max = img->val_max;
	uint64_t maska = 0xFFFF, maskb = 0xFFFF0000, maskc = 0xFFFF00000000;
	res->data = malloc(sizeof(uint64_t)*res->largeur*res->hauteur);
	for (int i = 0; i < res->hauteur; ++i)
	{
		for (int j = 0; j < res->largeur; ++j)
		{
			cond = alpha < ( ((*(img->data+i*img->largeur+j))&maska) * (((*(img->data+i*img->largeur+j))&maskb)>>16) * (((*(img->data+i*img->largeur+j))&maskc)>>32) ) / (res->val_max*res->val_max*res->val_max);
			*(res->data+i*res->largeur+j) = !cond;
			//printf("c%d l%d res=%lu\n", j, i, *(res->data+i*img->largeur+j));
		}
	}
	return res;
}

void ecrire(Image img, char * nomFichier){
	char * nomSortie = nomFichier;
	int i = 0;
	while(i < strlen(nomSortie)-3)
	{
		i++;
	}
	nomSortie[i] = 'p'; nomSortie[i+2] = 'm';
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