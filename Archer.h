#ifndef ARCHER_H
#define ARCHER_H


#include "Soldier.h"




class Archer : public Soldier
{
private:
	int arrows;
	double presicion;

public:


	int getArrows();
	void setArrows(double);
	double getPresicion();
	void setPresicion(double);

	double efficiencyAttack();
    double efficiencyDefense();

	Archer();
	Archer(string,int,string, int, double);
	~Archer();
	string toString();
};


#endif