OBJS	= main.o simulacao.o matrix.o dstring.o integral.o
SOURCE	= main.c simulacao.c matrix.c dstring.c integral.c
HEADER	= simulacao.h
OUT	    = simulacao
CC	    = gcc
FLAGS	= -g -c -Wall
LFLAGS	= -lpthread -lm

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.c
	$(CC) $(FLAGS) main.c -std=c11

simulacao.o: simulacao.c
	$(CC) $(FLAGS) simulacao.c -std=c11

matrix.o: matrix.c
	$(CC) $(FLAGS) matrix.c -std=c11

dstring.o: dstring.c
	$(CC) $(FLAGS) dstring.c -std=c11

integral.o: integral.c
	$(CC) $(FLAGS) integral.c -std=c11

clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	./$(OUT)

debug: $(OUT)
	valgrind $(OUT)

valgrind: $(OUT)
	valgrind $(OUT)

valgrind_leakcheck: $(OUT)
	valgrind --leak-check=full $(OUT)

valgrind_extreme: $(OUT)
	valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=high --track-origins=yes --vgdb=yes $(OUT)
