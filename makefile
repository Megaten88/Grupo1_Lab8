main: main.o Soldier.o Squad.o Archer.o Assassin.o HardArmor.o
	g++ main.o Soldier.o Squad.o Archer.o Assassin.o HardArmor.o -o main -lncurses

main.o: main.cpp Soldier.h Squad.h
	g++ -c main.cpp

Soldier.o: Soldier.h Soldier.cpp
	g++ -c Soldier.cpp

Squad.o: Soldier.h Squad.h Squad.cpp
	g++ -c Squad.cpp

Archer.o: Soldier.h Archer.h Archer.cpp
	g++ -c Archer.cpp

Assassin.o: Soldier.h Assassin.h Assassin.cpp
	g++ -c Assassin.cpp

HardArmor.o: Soldier.h HardArmor.h HardArmor.cpp
	g++ -c Assassin.cpp
clean:
	rm -f *.o main