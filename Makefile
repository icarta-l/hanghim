program:
	gcc game.c -o game.o -c
	gcc main.c -o main.o -c
	gcc -o launch main.o game.o

clean:
	rm *.o