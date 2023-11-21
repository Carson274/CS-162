CC = g++
exe_file = run

all: $(exe_file)

$(exe_file): catalog.o game.o run_catalog.o main.o
	$(CC) catalog.o game.o run_catalog.o main.o -o $(exe_file)

catalog.o: catalog.cpp catalog.h
	$(CC) -c catalog.cpp

game.o: game.cpp game.h
	$(CC) -c game.cpp

run_catalog.o: run_catalog.cpp catalog.h game.h
	$(CC) -c run_catalog.cpp

main.o: main.cpp game.h catalog.h
	$(CC) -c main.cpp

clean:
	rm -f *.o $(exe_file)