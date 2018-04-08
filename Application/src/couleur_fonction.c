#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "couleur_fonction.h"

uint64_t creer_pixel(uint64_t r,uint64_t g,uint64_t b){		//Fonction pour créer un pixel sur un uint64_t a partir de 3 uint64_t
  uint64_t res;
  b = b & MASKB;	// Le bleu n'est pas décalé
  g = g << DECALG;	// Le vert est decalé au milieu
  g = g & MASKG;	
  r = r << DECALR;	//Le rouge est décaler a la fin
  r = r & MASKR;	
  res = r+g+b;
  return res;
}


uint64_t R(uint64_t pix){	//restitue la couleur rouge a partir du piexel codé sur un uint64_t
  return (pix&MASKR)>>DECALR;
}


uint64_t G(uint64_t pix){	//restitue la couleur verte a partir du piexel codé sur un uint64_t
  return (pix&MASKG)>>DECALG;
}


uint64_t B(uint64_t pix){	//restitue la couleur bleu a partir du piexel codé sur un uint64_t
  return (pix&MASKB);
}
