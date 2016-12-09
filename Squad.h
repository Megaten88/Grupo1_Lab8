#pragma once
#include "Soldier.h"
#include <vector>
#include <string>
using std::vector;
using std::string;

class Squad
{
private:
	string name;
	vector<Soldier*> squad;
	double totalDef;
	double totalAttack;
public:
	Squad(string);
	void setName(string);
	string getName();
	string getSoldiers();
	void addSoldier(Soldier*);
	double getTotalDef();
	double getTotalAttack();
	~Squad();
	string toString();
};