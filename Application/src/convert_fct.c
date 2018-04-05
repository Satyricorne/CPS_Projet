#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "main.h"
#include "couleur_fonction.h"

Image gris(Image img, float a, float b, float c){
	Image res = malloc(sizeof(Image));
	res->type = P2;
	res->largeur = img->largeur;
	res->hauteur = img->hauteur;
	res->val_max = img->val_max;
	res->data = malloc(sizeof(uint64_t)*res->largeur*res->hauteur);
	for (int i = 0; i < res->hauteur; ++i)
	{
		for (int j = 0; j < res->largeur; ++j)
		{

			uint64_t rouge = a*R(*(img->data+i*img->largeur+j));
			uint64_t vert = b*G(*(img->data+i*img->largeur+j));
			uint64_t bleu = c*B(*(img->data+i*img->largeur+j));
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
	res->data = malloc(sizeof(uint64_t)*res->largeur*res->hauteur);
	for (int i = 0; i < res->hauteur; ++i)
	{
		for (int j = 0; j < res->largeur; ++j)
		{
			cond = alpha < (( B(*(img->data+i*img->largeur+j)) * G(*(img->data+i*img->largeur+j)) * R(*(img->data+i*img->largeur+j)) ) / (res->val_max*res->val_max*res->val_max));
			*(res->data+i*res->largeur+j) = !cond;
			//printf("c%d l%d res=%lu\n", j, i, *(res->data+i*img->largeur+j));
		}
	}
	return res;
}
