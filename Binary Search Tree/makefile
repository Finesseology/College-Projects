CC=g++
CFLAGS= -c
EXENAME=bst

default: main.o tree.o
	$(CC) main.o tree.o -o $(EXENAME)
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
tree.o: tree.cpp
	$(CC) $(CFLAGS) tree.cpp

clean:
	rm *o $(EXENAME)
