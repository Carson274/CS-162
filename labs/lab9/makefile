OBJS	= try_vector.o
SOURCE	= try_vector.cpp
HEADER	= vector.h
OUT	= run
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

try_vector.o: try_vector.cpp
	$(CC) $(FLAGS) try_vector.cpp 

clean:
	rm -f $(OBJS) $(OUT)