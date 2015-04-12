CC 		= g++
CFLAGS 	= -Wall
LDFLAGS = -lncurses

DEPS 	= view.hpp
OBJS 	= main.o view.o

all: kingdoms

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) -I.

kingdoms: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) -I.

clean:
	rm -rf *.o kingdoms

run:
	./kingdoms
