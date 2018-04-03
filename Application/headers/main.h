#include <stdint.h>
/* structure de l'image avec les différents */

enum Type {
	P1 = 1,
	P2 = 2,
	P3 = 3
};

typedef enum Type Type;

typedef struct image {
  Type type;				//Voici la variable type de type Type ;)
  uint32_t largeur;
  uint32_t hauteur;
  int val_max;
  uint64_t * data;  
} image;

typedef image * Image;
