CC = g++ -g
EXE = driver

$(EXE): book.o driver.o
	$(CC) book.o driver.o -o $(EXE)

book.o: book.cpp
	$(CC) -c book.cpp

clean: 
	rm -f *.o $(EXE)

leak_check: book.o driver.o
	$(CC) book.o driver.o -o $(EXE)
	valgrind --leak-check=full ./$(EXE)