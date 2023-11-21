CC = g++
exe_file = run

all: $(exe_file)

$(exe_file): fruit.o
	$(CC) fruit.o -o $(exe_file)

fruit.o: fruit.cpp fruit.h
	$(CC) -c fruit.cpp

clean:
	rm -f *.o $(exe_file)