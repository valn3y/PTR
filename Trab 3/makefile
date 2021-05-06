### Makefile Trabalho 3
### By: Josias Ben e Valney Marinho

all: trab3

trab3: main.o operationMatrix.o
	gcc main.o operationMatrix.o -o trab3

sum.o: sum.c
	gcc -c sum.c -o operationMatrix.o

main.o: main.c
	gcc -c main.c -o main.o

run: trab3
	./trab3

clean:
	rm -f main.o operationMatrix.o trab3