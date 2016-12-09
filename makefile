main: main.o Soldier.o Squad.o
	g++ main.o Soldier.o Squad.o -o main -lncurses

main.o: main.cpp Soldier.h Squad.h
	g++ -c main.cpp

Soldier.o: Soldier.h Soldier.cpp
	g++ -c Soldier.cpp

Squad.o: Soldier.h Squad.h Squad.cpp
	g++ -c Squad.cpp

clean:
	rm -f *.o main