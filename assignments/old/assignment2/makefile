CC = g++ -g
EXE = run_catalog

$(EXE): catalog.o run_catalog.o
	$(CC) catalog.o run_catalog.o -o $(EXE)

catalog.o: catalog.cpp
	$(CC) -c catalog.cpp

clean: 
	rm -f *.o $(EXE)

leak_check: catalog.o run_catalog.o
	$(CC) catalog.o run_catalog.o -o $(EXE)
	valgrind --leak-check=full ./$(EXE)