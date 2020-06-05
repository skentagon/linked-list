exe_file = listtest.out
CC = g++ -std=c++11 

$(exe_file): main.o
		$(CC) -o $(exe_file) main.o

main.o:	src/main.cpp src/linked_list.hpp src/node.hpp
		$(CC) -c src/main.cpp

clean:
		rm -f *.out *.o $(exe_file)