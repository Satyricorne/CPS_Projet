#include <stdio.h>
#include <stdlib.h>
#include "../headers/main.h"

int lire(int argc, char const *argv[])
{
	int convert = 0;
	FILE * image = fopen("./Exemples/poivron.ppm", "r");
	if (argc == 0)
	{
		printf("Aucun fichier selectionné\n");
	} else if (argc == 1) {
		convert = 1;
	} else if(argc == 2){
		image = fopen(argv[1], "r");
		convert = 2;
	}

	printf("fichier extrait\n");

	Image img;
	char carac;
	fscanf(image, "%c%d\n", &carac, &(img->type));
	printf("%d\n", img->type);

	return 0;
}
