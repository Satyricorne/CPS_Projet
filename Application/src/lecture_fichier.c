#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
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

	char carac;
	int num;
	fscanf(image, "%c%d", &carac, &num);
	printf("%c%d\n", carac, num);
	char carac2 = num;
	printf("%c\n", carac2);
	return 0;
}