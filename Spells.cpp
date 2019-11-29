#include "Spells.h"
Spell::Spell(string n, int v,int l, int dmg, int mpc):name(n),price(v),level_required(l),damage(dmg),magic_power_cost(mpc){

}
string Spell::get_name()const{ return name;}
int Spell::get_price()const{ return price;}
int Spell::get_level_required()const{ return level_required;}

IceSpell::IceSpell(string n, int v,int l, int dmg, int mpc):Spell(n,v,l,dmg,mpc){
}
FireSpell::FireSpell(string n, int v,int l, int dmg, int mpc):Spell(n,v,l,dmg,mpc){
}
LightingSpell::LightingSpell(string n, int v,int l, int dmg, int mpc):Spell(n,v,l,dmg,mpc){
}
