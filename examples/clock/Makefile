CC = g++
FLAGS = -Wall -O2 `lxrad-config --cxxflags`

OBJS = pclock.o clock1.o  


all: $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -oclock `lxrad-config --libs`

%.o: %.cc
	$(CC) -c $(FLAGS) $< 

run: all
	./clock

install:

clean:
	rm -f clock *.o core
