SRC = ../src/
BIN = ../bin/
HEAD = ../headers/
OPTION = -Wall -I$(HEAD)
CC = gcc

traitement_image: lecture_ecriture.o convert.o
	$(CC) $(OPTION) -o $(BIN)traitement_image main.c $(BIN)lecture_ecriture.o $(BIN)convert_fct.o

lecture_ecriture.o: lecture_ecriture.c $(HEAD)main.h
	$(CC) $(OPTION) -c $(SRC)lecture_ecriture.c -o $(BIN)lecture_ecriture.o

convert.o: convert_fct.c $(HEAD)main.h $(HEAD)convert_fct.h
	$(CC) $(OPTION) -c $(SRC)convert_fct.c -o $(BIN)convert_fct.o
