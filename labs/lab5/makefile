CC = g++
exe_file = run

all: $(exe_file)

$(exe_file): coffee.o coffee_run.o
	$(CC) coffee.o coffee_run.o -o $(exe_file)

coffee.o: coffee.cpp coffee.h
	$(CC) -c coffee.cpp

run_catalog.o: coffee_run.cpp coffee.h game.h
	$(CC) -c coffee_run.cpp

clean:
	rm -f *.o $(exe_file)