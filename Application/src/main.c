#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "lecture_ecriture.h"
#include "convert_fct.h"


void transform(char * file, char * option){

	Image img = malloc(sizeof(Image));
	if(file == NULL){
		lecture_std(img);
	}else{
		lire(img, file);
	}
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
  if(argc < 2){
    printf("Problème d'argument vous devez saisir l'executable, l'option et le fichier à modifier");
  }else{
		printf("Argument 2 : a%sa \n ", argv[2]);
    transform(argv[2], argv[1]);
  }
}
