CC = g++
FLAGS = -Wall -O2 `lxrad-config --cxxflags`

OBJS = psimple.o simple1.o  


all: $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -osimple `lxrad-config --libs`

%.o: %.cc
	$(CC) -c $(FLAGS) $< 

run: all
	./simple

install:

clean:
	rm -f simple *.o core
