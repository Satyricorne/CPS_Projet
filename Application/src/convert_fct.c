#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "main.h"


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
