gcc -c configreader.c
gcc -c queue.c
gcc -c main.c -lpthread
gcc -o router main.o queue.o configreader.o