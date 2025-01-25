CC = g++ -g
EXE = main 

$(EXE): vehicle.o car.o bus.o main.cpp
	$(CC) vehicle.o car.o bus.o main.cpp -o $(EXE)

vehicle.o: vehicle.cpp
	$(CC) -c vehicle.cpp

car.o: car.cpp
	$(CC) -c car.cpp

bus.o: bus.cpp
	$(CC) -c bus.cpp

clean: 
	rm -f *.o $(EXE)
