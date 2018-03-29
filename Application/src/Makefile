SRC = ../src/
BIN = ../bin/
HEAD = ../headers/
OPTION = -Wall
CC = gcc

traitement_image : main.o lecture_fichier.o
	$(CC) $(OPTION) -o traitement_image main.o lecture_fichier.o

lecture_fichier.o: lecture_fichier.c $(HEAD)lecture_fichier.h
	$(CC) $(OPTION) -c $(SRC)lecture_fichier.c

main.o: main.c $(HEAD)main.h
	$(CC) $(OPTION) -c $(SRC)main.c
