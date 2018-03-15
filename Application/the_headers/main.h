/* structure de l'image avec les différents */

typedef struct image {
  int type;
  int largeur;
  int hauteur;
  int val_max;
  int image[largeur][hauteur];  
} image, *image ;
