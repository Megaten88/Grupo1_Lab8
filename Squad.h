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
	int totalDef;
	int totalAttack;
public:
	Squad(string);
	void setName(string);
	string getName();
	string getSoldiers();
	void addSoldier(Soldier*);
	int getTotalDef();
	int getTotalAttack();
	~Squad();
	string toString();
};