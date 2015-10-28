CC = g++
FLAGS = -Wall -O2 `lxrad-config --cxxflags`

OBJS = psin.o sin1.o  


all: $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -osin `lxrad-config --libs`

%.o: %.cc
	$(CC) -c $(FLAGS) $< 

run: all
	./sin

install:

clean:
	rm -f sin *.o core
