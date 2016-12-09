#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Soldier{
private:
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

    virtual double efficiencyAttack();
    virtual double efficiencyDefense();

    virtual string toString();
};
