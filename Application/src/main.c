#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/main.h"
#include "../headers/lecture_fichier.h"


void transform(char * file, char * option){
	Image img = malloc(sizeof(Image));
	lire(img, file);
	Image sortie = malloc(sizeof(Image));
	if (img->type == P3 && !strcmp(option, "-g")){
		sortie = gris(img, 0.299, 0.587, 0.114);
	} else if (img->type == P3 && !strcmp(option, "-b"))
	{
		sortie = noir(img, 0.5);
	}
	ecrire(sortie, file);
		
	
}

int main(int argc, char *argv[]) {
  if(argc != 3){
    printf("Problème d'argument vous devait saisir l'executable, l'option et le fichier à modifier");
  }else{
    transform(argv[2], argv[1]);
  }
}
