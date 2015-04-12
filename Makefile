CC=g++
CFLAGS=-Wall
LDFLAGS=-lncurses

all: kingdoms

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

kingdoms: main.o
	$(CC) -o kingdoms main.o $(CFLAGS) $(LDFLAGS)

clean:
	rm -rf *.o kingdoms

run:
	./kingdoms
