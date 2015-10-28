CC = g++
FLAGS = -Wall -O2 `lxrad-config --cxxflags`

OBJS = pgeditor.o geditor1.o  


all: $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -ogeditor `lxrad-config --libs`

%.o: %.cc
	$(CC) -c $(FLAGS) $< 

run: all
	./geditor

install:

clean:
	rm -f geditor *.o core
