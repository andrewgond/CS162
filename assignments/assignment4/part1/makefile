CC=g++ -std=c++11 -g
exe=wumpus

# Complete the makefile
# Your code here: 

$(exe): room.o event.o pool.o stalactites.o game.o wumpus.o gold.o armor.o main.cpp
	$(CC) room.o event.o pool.o stalactites.o game.o wumpus.o gold.o armor.o main.cpp -o $(exe)

room.o: room.cpp
	$(CC) -c room.cpp

event.o: event.cpp
	$(CC) -c event.cpp

pool.o: pool.cpp
	$(CC) -c pool.cpp

stalactites.o: stalactites.cpp
	$(CC) -c stalactites.cpp

game.o: game.cpp
	$(CC) -c game.cpp

wumpus.o: wumpus.cpp
	$(CC) -c wumpus.cpp

gold.o: gold.cpp
	$(CC) -c gold.cpp

armor.o: armor.cpp
	$(CC) -c armor.cpp

clean: 
	rm -f *.o $(exe)
