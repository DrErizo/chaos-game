all: compile link clean

compile:
	gcc -c src/*.c -g

link:
	gcc -o bin/erizos-chaos-game main.o -l SDL2main -l SDL2 -g
 
clean:
	rm *.o
