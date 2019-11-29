#include "Items.h"

Item::Item(const string n, const int p, const int ml):name(n),price(p),min_level(ml){
}
Item::Item(const Item& temp){
    name=temp.name;
    price=temp.price;
    min_level=temp.min_level;
}
string Item::get_name()const{return name;}
int Item::get_price()const{ return price;}
int Item::get_min_level()const{ return min_level;}


Weapon::Weapon(const string n ,const int p,const int ml,const int d,const int h):Item(n,p,ml),damage(d),hands(h){}

Armor::Armor (string n,int p,int ml,int ds):Item(n,p,ml),defense_status(ds){}

Potion::Potion (string n,int p,int ml,int r,string t):Item(n,p,ml),rate(r),type(t){}




