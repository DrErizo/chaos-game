LIBS += -l SDL2main -l SDL2 
OBJS = main.o

all: compile link clean

compile:
	gcc -c src/*.c

link:
	gcc -o bin/erizos-chaos-game $(OBJS) $(LIBS)

clean:
	rm *.o
