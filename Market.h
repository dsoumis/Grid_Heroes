#ifndef RPG_MARKET_H
#define RPG_MARKET_H
#include "Items.h"
#include "Spells.h"
class Market{
    Item** catalogue_of_Items;
    Spell** catalogue_of_Spells;
public:
    Market(){
        catalogue_of_Items=new Item*[30]; //Create a table of pointers to items
        catalogue_of_Spells=new Spell*[9];
        market_buildup();
    }
    ~Market(){
        for(int i=0; i<30; i++)
            delete catalogue_of_Items[i];
        delete[] catalogue_of_Items;
        for(int i=0; i<9; i++)
            delete catalogue_of_Spells[i];
        delete catalogue_of_Spells;
    }
    void market_buildup();
    void market_operate(Hero&);
};
#endif
