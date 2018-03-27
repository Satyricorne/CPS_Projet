/* structure de l'image avec les différents */

enum Type {
	P1 = 1,
	P2 = 2,
	P3 = 3
};

typedef struct image {
  int type;
  int largeur;
  int hauteur;
  int val_max;
  int * data;  
} image;

typedef image * Image;
