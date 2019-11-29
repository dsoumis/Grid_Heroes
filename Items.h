#ifndef RPG_ITEMS_H
#define RPG_ITEMS_H
#include <iostream>
#include <string>
#include <cstdlib>
#include "Livings.h"
using namespace std;


class Item{
private:
    string name;
    int price;
    int min_level;
public:
    Item(string n ,int p,int ml);
    Item(const Item&);
    virtual ~Item(){};
    string get_name()const;
    int get_price()const;
    int get_min_level()const;
    virtual int get_damage()const{};
    virtual int get_hands()const{};
    virtual int get_armor()const{};
    virtual int get_rate()const{};
    virtual string get_type()const{};
};


class Weapon : public Item {
private:
    int damage;       //rate
    int hands;        //1 or 2
public:
    Weapon(string n ,int p,int ml,int d,int h);
    ~Weapon(){ cout<<"I just destroyed a weapon "<<get_name()<<"."<<endl; };
    int get_damage()const{return damage;};
    int get_hands()const{return hands;};
};



class Armor : public Item{
private:
    int defense_status;
public:
    Armor (string,int,int,int);
    ~Armor (){ cout<<"I just destroyed "<<get_name()<<"."<<endl; }
    int get_armor()const{ return defense_status;};
};
class Potion : public Item{
private:
    int rate;
    string type; // Health potion/Magic Potion/Strength Potion/Dexterity Potion/Agility Potion
public:
    Potion (string,int,int,int,string);
    ~Potion(){cout<<"I just destroyed a "<<get_name()<<"."<<endl; };
    int get_rate()const{ return rate;};
    string get_type()const{ return type;};
};


#endif //RPG_ITEMS_H
