compile:program 
program:library mainFile
	gcc matrixLib.o main.o -o program
library:
	gcc -c matrixLib.c -o matrixLib.o
mainFile:
	gcc -c main.c -o main.o
	