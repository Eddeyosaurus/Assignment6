CC = g++

all: ass6

ass6: Graph.o Queue.o List.o UnionFind.o Client.o
	$(CC) Graph.o Queue.o List.o UnionFind.o Client.o -o ass6

Graph.o: Graph.cpp
	$(CC) -c Graph.cpp

Queue.o: Queue.cpp
	$(CC) -c Queue.cpp

List.o: List.cpp
	$(CC) -c List.cpp

UnionFind.o: UnionFind.cpp
	$(CC) -c UnionFind.cpp

Client.o: Client.cpp
	$(CC) -c Client.cpp

clean:
	rm *.o ass6