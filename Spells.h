#ifndef PROJECT_SPELLS_H
#define PROJECT_SPELLS_H
#include <iostream>
#include <string>
#include "Livings.h"
using namespace std;

class Spell{
    string name;
    int price;
    int level_required;
    int damage;
    int magic_power_cost;
public:
    Spell(string,int,int,int,int);
    string get_name()const;
    int get_price()const;
    int get_level_required()const;
    int get_magic_power_cost()const{ return magic_power_cost;};
    int get_damage()const{ return damage;}
};

class IceSpell : public Spell{
public:
    IceSpell(string,int,int,int,int);
};

class FireSpell : public Spell{
public:
    FireSpell(string,int,int,int,int);
};

class LightingSpell : public Spell{
public:
    LightingSpell(string,int,int,int,int);
};




#endif //PROJECT_SPELLS_H
