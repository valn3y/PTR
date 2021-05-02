### Makefile Trabalho 1 ###
###By: Josias Ben e Valney Marinho###

all: trab1

trab1: main.o sum.o subtraction.o
	gcc main.o sum.o subtraction.o -o trab1

subtraction.o: subtraction.c
	gcc -c subtraction.c -o subtraction.o

sum.o: sum.c
	gcc -c sum.c -o sum.o

main.o: main.c
	gcc -c main.c -o main.o

run: trab1
	./trab1