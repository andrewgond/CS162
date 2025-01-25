CC=g++ --std=c++11 -g

all: list recur

linked_list.o: linked_list.h linked_list.cpp node.h
	$(CC) -c linked_list.cpp

test_linked_list.o: test_linked_list.cpp 
	$(CC) -c test_linked_list.cpp

list: linked_list.o test_linked_list.o
	$(CC) linked_list.o test_linked_list.o -o list

recur: recursion.cpp
	$(CC) recursion.cpp -o recur

clean:
	rm -f *.o list recur