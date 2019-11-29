#ifndef RPG_GRID_H
#define RPG_GRID_H
#include <string>
#include <iostream>
#include "Livings.h"
#include "Market.h"
#include "Battlefield.h"
using namespace std;
string** create_grid();
void move(string** grid,int& lastmovei,int& lastmovej,Hero *heroes[],int type_of_hero[],const int& heroes_quantity,Market& market);
void displayMap(string** grid);
#endif
