CC = g++
exe_file = prog


$(exe_file): struct.o prog.cpp
	$(CC) prog.cpp struct.o -o $(exe_file)

struct.o: struct.cpp
	$(CC) -c struct.cpp


clean:
	rm -f *.o $(exe_file)