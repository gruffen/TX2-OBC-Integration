test: test.o
			g++ -o test test.o uart_c.o

test.o: uart_c.o
				g++ -c test.cpp

uart_c: uart_c.cpp uart_c.hpp
				g++ -c uart_c.cpp
