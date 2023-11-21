OBJS	= main.o fruit.o apple.o watermelon.o Granny_Smith.o
SOURCE	= main.cpp fruit.cpp apple.cpp watermelon.cpp Granny_Smith.cpp
HEADER	= fruit.h apple.h watermelon.h Granny_Smith.h
OUT	= run
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

fruit.o: fruit.cpp
	$(CC) $(FLAGS) fruit.cpp 

apple.o: apple.cpp
	$(CC) $(FLAGS) apple.cpp 

watermelon.o: watermelon.cpp
	$(CC) $(FLAGS) watermelon.cpp 

Granny_Smith.o: Granny_Smith.cpp
	$(CC) $(FLAGS) Granny_Smith.cpp 


clean:
	rm -f $(OBJS) $(OUT)