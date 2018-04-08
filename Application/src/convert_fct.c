#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "main.h"
#include "couleur_fonction.h"

Image gris(Image img, float a, float b, float c){	// Fonction pour passer une image couleur a une nuance de gris
	Image res = malloc(sizeof(Image));
	res->type = P2;										//On crée une image avec les même parametre sauf le type qui devient P2
	res->largeur = img->largeur;
	res->hauteur = img->hauteur;
	res->val_max = img->val_max;
	res->data = malloc(sizeof(uint64_t)*res->largeur*res->hauteur);
	for (int i = 0; i < res->hauteur; ++i)				// Pour chaque pixel on le transforme en un nombre compris entre 0 et val_max selon ses trois couleur primaire et les variable a, b et c qui donneront plus ou moins de poids a une couleur dans la nuance de gris
	{
		for (int j = 0; j < res->largeur; ++j)
		{

			uint64_t rouge = a*R(*(img->data+i*img->largeur+j));
			uint64_t vert = b*G(*(img->data+i*img->largeur+j));
			uint64_t bleu = c*B(*(img->data+i*img->largeur+j));
			*(res->data+i*res->largeur+j) = rouge + vert + bleu;
		}
	}
	return res;
}


Image noir(Image img, float alpha){				// Fonction pour passer une image couleur a une image noir et blanc
	int cond;
	Image res = malloc(sizeof(Image));				//On crée une image avec les même parametre sauf le type qui devient P1
	res->type = P1;
	res->largeur = img->largeur;
	res->hauteur = img->hauteur;
	res->val_max = img->val_max;
	res->data = malloc(sizeof(uint64_t)*res->largeur*res->hauteur);
	for (int i = 0; i < res->hauteur; ++i)			// Pour chaque pixel on le transforme en 1 ou 0 selon la valeur de alpha et la valeur de ses trois couleur primaire
	{
		for (int j = 0; j < res->largeur; ++j)
		{
			cond = alpha < (( B(*(img->data+i*img->largeur+j)) * G(*(img->data+i*img->largeur+j)) * R(*(img->data+i*img->largeur+j)) ) / (res->val_max*res->val_max*res->val_max));
			*(res->data+i*res->largeur+j) = !cond;
		}
	}
	return res;
}
