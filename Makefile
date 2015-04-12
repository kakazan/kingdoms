CC=gcc
CFLAGS=-Wall
LDFLAGS=-lncurses
BUILD_DIR=./build

all: kingdoms

%.o: %.c $(DEPS)
	$(CC) -c -o $(BUILD_DIR)/$@ $< $(CFLAGS)

kingdoms: main.o
	$(CC) -o kingdoms main.o $(CFLAGS) $(LDFLAGS)

clean:
	rm -rf $(BUILD_DIR)/*.o kingdoms

run:
	./kingdoms
