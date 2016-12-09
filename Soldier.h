#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Soldier{
protected:
    string name;
    int age;
    string city;
public:
    Soldier();
    virtual ~Soldier();
    Soldier(string,int,string);

    void setName(string);
    string getName();

    void setAge(int);
    int getAge();

    void setCity(string);
    string getCity();

    virtual int efficiencyAttack();
    virtual int efficiencyDefense();

    virtual string toString();
};
