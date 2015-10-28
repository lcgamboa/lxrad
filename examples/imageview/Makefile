CC = g++
FLAGS = -Wall -O2 `lxrad-config --cxxflags`

OBJS = pimageview.o imageview1.o  


all: $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -oimageview `lxrad-config --libs`

%.o: %.cc
	$(CC) -c $(FLAGS) $< 

run: all
	./imageview

install:

clean:
	rm -f imageview *.o core
