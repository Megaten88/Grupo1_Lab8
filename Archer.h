#ifndef ARCHER_H
#define ARCHER_H


#include "Soldier.h"




class Archer : public Soldier
{
private:
	int arrows;
	int presicion;

public:


	int getArrows();
	void setArrows(int);
	int getPresicion();
	void setPresicion(int);

	double efficiencyAttack();
    double efficiencyDefense();

	Archer();
	Archer(string,int,string, int, int);
	~Archer();
	string toString();
};


#endif