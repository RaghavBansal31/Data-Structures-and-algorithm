EXEC = run
CC = g++
CFLAGS = -c -Wall
$(EXEC) :main.o	util.o	heap.o	graph.o	nc.o

	$(CC) -o $(EXEC) main.o	util.o	heap.o	graph.o	nc.o

main.o:main.cpp
	$(CC) $(CFLAGS)	main.cpp
heap.o :heap.cpp
	$(CC) $(CFLAGS) heap.cpp
util.o :util.h util.cpp
	$(CC) $(CFLAGS) util.cpp
nc.o :nc.cpp
	$(CC) $(CFLAGS) nc.cpp
graph.o :graph.cpp
	$(CC) $(CFLAGS) graph.cpp
clean :
	rm *.o
