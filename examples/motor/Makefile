CC = g++
FLAGS = -Wall -O5 `lxrad-config --cxxflags`

OBJS = pmotor.o motor1.o  


all: $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -omotor `lxrad-config --libs`

%.o: %.cc
	$(CC) -c $(FLAGS) $< 

run: all
	./motor

install:

clean:
	rm -f motor *.o core
