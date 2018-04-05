#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "couleur_fonction.h"

uint64_t creer_pixel(uint64_t r,uint64_t g,uint64_t b){
  uint64_t res;
  b = b & MASKB;
  g = g << DECALG;
  g = g & MASKG;
  r = r << DECALR;
  r = r & MASKR;
  res = r+g+b;
  return res;
}


uint64_t R(uint64_t pix){
  return (pix&MASKR)>>DECALR;
}


uint64_t G(uint64_t pix){
  return (pix&MASKG)>>DECALG;
}


uint64_t B(uint64_t pix){
  return (pix&MASKB);
}
