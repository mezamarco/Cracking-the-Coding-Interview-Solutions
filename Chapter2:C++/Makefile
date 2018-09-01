all: main

main: main.o LinkedList.o Node.o
	g++ -g -o main main.o LinkedList.o Node.o


main.o: main.cpp LinkedList.h Node.h
	g++ -c -g main.cpp

LinkedList.o: LinkedList.cpp LinkedList.h Node.h
	g++ -c -g LinkedList.cpp

Node.o: Node.cpp Node.h
	g++ -c -g Node.cpp

clean:
	rm *.exe *.o
