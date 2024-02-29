all: compile link clean

compile:
	gcc -c src/*.c

link:
	gcc -o bin/erizos-chaos-game main.o -l SDL2main -l SDL2

clean:
	rm *.o
