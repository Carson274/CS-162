CC = g++ -g
exe_file = run

$(exe_file): main.cpp point.o
$(CC) main.cpp point.o -o $(exe_file)

point.o: point.h point.cpp
$(CC) -c point.cpp

clean:
rm -f *.o $(exe_file)