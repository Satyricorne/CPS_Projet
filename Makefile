SRC = Application/src/
BIN = Application/bin/
HEAD = Application/headers
OPTION = -Wall -I$(HEAD)

main: main.o lecture_fichier.o
	gcc -o main $(SRC)main.c $(OPTION)

main.o: main.c 
	gcc -o $(BIN)main.o $(SRC)main.c $(OPTION)

lecture_fichier.o: lecture_fichier.c main.h
	gcc -o $(BIN)lecture_fichier.o $(SRC)lecture_fichier.c $(OPTION)

