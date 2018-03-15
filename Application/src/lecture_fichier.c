#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE * image = fopen("../Exemples/img1.ppm", "r");
	if (argc == 0)
	{
		printf("Aucun fichier selectionné\n");
	} else {
		image = fopen(argv[1], "r");
	}

	printf("fichier extrait\n");

	int nb;
	fscanf(image, "%d", &nb);
	printf("%d\n", nb);
	return 0;
}