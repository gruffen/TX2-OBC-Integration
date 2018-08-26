test2: test2.o
	g++ -o test2 test2.o uart_c.o

test2.o: uart_c.o
	g++ -c test2.cpp

test: test.o
			g++ -o test test.o uart_c.o

test.o: uart_c.o
				g++ -c test.cpp

uart_c: uart_c.cpp uart_c.hpp
				g++ -c uart_c.cpp
