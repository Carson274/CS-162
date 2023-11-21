CC = g++ -g
exe_file = run

all: $(exe_file)

$(exe_file): coffee.o display.o menu.o order.o prog.o shop.o
	$(CC) coffee.o display.o menu.o order.o prog.o shop.o -o $(exe_file)

coffee.o: coffee.cpp coffee.h
	$(CC) -c coffee.cpp

display.o: display.cpp display.h
	$(CC) -c display.cpp

menu.o: menu.cpp menu.h
	$(CC) -c menu.cpp

order.o: order.cpp order.h
	$(CC) -c order.cpp

shop.o: shop.cpp shop.h
	$(CC) -c shop.cpp

clean:
	rm -f *.o $(exe_file)