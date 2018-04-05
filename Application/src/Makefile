SRC = ../src/
BIN = ../bin/
HEAD = ../headers/
OPTION = -Wall -I$(HEAD)
CC = gcc

traitement_image: lecture_ecriture.o convert.o couleur_fonction.o
	$(CC) $(OPTION) -o $(BIN)traitement_image main.c $(BIN)lecture_ecriture.o $(BIN)convert_fct.o $(BIN)couleur_fonction.o

lecture_ecriture.o: lecture_ecriture.c $(HEAD)main.h $(HEAD)couleur_fonction.h
	$(CC) $(OPTION) -c $(SRC)lecture_ecriture.c -o $(BIN)lecture_ecriture.o

convert.o: convert_fct.c $(HEAD)main.h $(HEAD)convert_fct.h $(HEAD)couleur_fonction.h
	$(CC) $(OPTION) -c $(SRC)convert_fct.c -o $(BIN)convert_fct.o

couleur_fonction.o: couleur_fonction.c $(HEAD)couleur_fonction.h
	$(CC) $(OPTION) -c $(SRC)couleur_fonction.c -o $(BIN)couleur_fonction.o
