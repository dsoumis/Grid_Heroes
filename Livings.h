#ifndef RPG_LIVINGS_H
#define RPG_LIVINGS_H
#include <iostream>
#include <string>
#include <cstdlib>     /* srand, rand */
#include "Items.h"
#include "Spells.h"
#include "Lists.h"
using namespace std;
class Item;
class Living{
    string name;
    int level;
    int healthPower;
    int maxHealth;
public:
    Living(string,int,int);
    Living(){}; //Default constructor in order the default constructor of monsters to work
    virtual ~Living(){cout<<"to homeland."<<endl;};
    void health_from_damage(double);
    void increase_level();
    int get_level()const;
    int get_hp()const;
    string get_name()const;
    void increase_hp(int);
};
class Monster;
class Item_List;
class Spell_List;
class Hero: public Living{
    int magicPower,strength,dexterity,agility,money,experience,defense; //of Hero
    int adaptive_leveling_value; //Increases each time the hero levels-up(to make it more difficult to reach the next level)
    int maxMagic;
    Item_List *Inventory;
    Spell_List *Spells;
    int inventory_place,spell_place;
    int equipped_armor,equipped_left_weapon,equipped_right_weapon,equipped_two_hands_weapon;
public:
    Hero(string,int,int,int,int,int,int,int,int,int);
    virtual ~Hero();

    int get_magicPower()const; //Info for hero
    int get_strength()const;
    int get_dexterity()const;
    int get_money()const;
    int get_agility()const;
    int get_defense()const;
    int get_weapon_damage()const;

    bool escaped_the_attack()const;
    void levelUp(int);
    void decrease_magicPower(int);


    void increase_health(int);
    void increase_magicPower(int);
    void increase_strength(int);
    void increase_dexterity(int);
    void increase_agility(int);
    void increase_experience(int);

    void put_in_inventory(Item*); //Functions for market and Inventory checking
    void put_in_spells(Spell*);
    int checkInventory(bool);
    int checkSpells()const;
    void sell_from_inventory(int);
    void sell_from_spells(int);


    void usePotion(int); //Use items
    void equip_armor(int);
    void equip_weapon(int);
    void equip_from_inventory(int);

    int useSpell(int,Monster&);

    int attack(Monster&); //Heroes' attack no.1
    int castSpell(Monster&); //Heroes' attack no.2

    void decrease_life(int);
};

class Warrior : public Hero{
public:
    Warrior(string,int,int,int,int,int,int,int,int,int);
    ~Warrior(){ cout<<"Warrior "<<get_name()<<" left the battlefield "; };
    void levelUp();
};

class Sorcerer : public Hero{
public:
    Sorcerer(string,int,int,int,int,int,int,int,int,int);
    ~Sorcerer(){ cout<<"Sorcerer "<<get_name()<<" left the battlefield "; };
    void levelUp();
};

class Paladin : public Hero{
public:
    Paladin(string,int,int,int,int,int,int,int,int,int);
    ~Paladin(){ cout<<"Paladin "<<get_name()<<" left the battlefield "; };
    void levelUp();
};


class Monster : public Living{
    int attack_damage,defense,escape_probability;
public:
    Monster(string,int,int,int,int,int);
    Monster(){}; //Default constructor for making an array[][] of monsters in battlefield.cpp
    virtual ~Monster(){cout<<"returned ";};
    int get_attack_damage()const;
    int get_escape_probability()const;
    int get_defense()const;
    void decrease_defense(int);

    bool escaped_the_attack()const;
    int decrease_only_defense(int);
    int decrease_damage(int);
    int decrease_escape_probability(int);
    void resume_damage(int);
    void resume_defense(int);
    void resume_escape_probability(int);

    void attack_hero(Hero&);
};

class Dragon : public Monster{
public:
    Dragon(string,int,int,int,int,int);
    ~Dragon(){cout<<"A dragon was destroyed and ";};
};


class Exoskeleton : public Monster{
public:
    Exoskeleton(string,int,int,int,int,int);
    ~Exoskeleton(){ cout<<"A Exoskeleton was destroyed and "; };
};


class Spirit : public Monster{
public:
    Spirit(string,int,int,int,int,int);
    ~Spirit(){ cout<<"A Spirit was destroyed and "; };
};

#endif
