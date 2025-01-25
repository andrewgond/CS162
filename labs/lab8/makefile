CC = g++ -g
EXE = main 

$(EXE): vehicle.o car.o bus.o bot.o main.o
	$(CC) vehicle.o car.o bus.o bot.o main.o -o $(EXE)

vehicle.o: vehicle.cpp
	$(CC) -c vehicle.cpp

car.o: car.cpp
	$(CC) -c car.cpp

bus.o: bus.cpp
	$(CC) -c bus.cpp

bot.o: bot.cpp
	$(CC) -c bot.cpp

clean: 
	rm -f *.o $(EXE)
