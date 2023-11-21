CC=g++
EXE_FILE=student_db_run

all: $(EXE_FILE)

$(EXE_FILE): student_db.o student_db.h prog.cpp
	$(CC) student_db.o prog.cpp -o $(EXE_FILE)

multdiv.o: student_db.h student_db.cpp
	$(CC) -c student_db.cpp

clean:
	rm -f *.o $(EXE_FILE)