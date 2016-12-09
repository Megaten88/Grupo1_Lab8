#include "Soldier.h"

class Assassin : public Soldier
{
private:
	int kills;
	int presence;

public:
	int getKills();
	void setKills(int);
	int getPresence();
	void setPresence(int);

	Assassin(string,int,string, int , int);
	Assassin();
	~Assassin();

	int efficiencyAttack();
    int efficiencyDefense();

	string toString();
	
};