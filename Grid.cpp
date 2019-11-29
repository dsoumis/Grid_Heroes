#include "Grid.h"
string** create_grid(){
    string** grid = new string*[10];
    for(int i = 0; i < 10; ++i)
        grid[i] = new string[10];

    for(int i=0; i<10; i++){		//initialize
        for(int j=0;j<10;j++){
            grid[i][j]=".";
        }
    }

    grid[0][0]="M H";				//creating markets
    grid[5][2]="M";
    grid[8][8]="M";

    grid[0][8]=grid[0][9]=grid[1][9]="X";       //creating non-accessible areas
    grid[2][5]="X";
    grid[4][2]=grid[4][3]=grid[5][3]="X";
    grid[8][4]=grid[8][5]=grid[9][4]="X";
    grid[7][1]=grid[8][1]="X";
    grid[4][8]="X";
    return grid;
}
int check_grid(string place){
    if(place=="X"){
        cout<<"This area is non-accessible!"<<endl;
        return 0;
    }else if(place=="M"){
        cout<<"Loading Market..."<<endl;
        return 1;
    }else{
        return 2;
    }


}
void move(string** grid,int& lastmovei,int& lastmovej,Hero *heroes[],int type_of_hero[],const int& heroes_quantity,Market& market){
    string s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11,s12;
    string move;
    cout<<"TIP:"<<endl<<"It's recommended at first round to buy a weapon/armor with a Small Health Potion and a Spell."<<endl;
    for (int i = 0; i < heroes_quantity; i++) {
        market.market_operate(*heroes[i]);            //calls market function for each hero
    }
    cout<<"TIP:"<<endl<<"It's recommended to equip your items from each hero's inventory."<<endl;
    for (int i = 0; i < heroes_quantity; i++) {
        heroes[i]->checkInventory(true);
    }
    int counter=0;
    while(true) {
        for(int i=0; i<heroes_quantity; i++){
            if(heroes[i]->get_hp()<=0)
                counter++;
        }
        if(counter==heroes_quantity){
            cout<<"GAME OVER!"<<endl;
        }else counter=0;
        do {
            cout << "Press A to move left" << endl;
            cout << "Press D to move right" << endl;
            cout << "Press W to  move up" << endl;
            cout << "Press S to move down" << endl;
            cout << "Press Q to quit the game" << endl;
            cout << "Press M to see the map" << endl;
            s1 = "A";
            s2 = "W";
            s3 = "D";
            s4 = "S";
            s5 = "a";
            s6 = "w";
            s7 = "d";
            s8 = "s";
            s9 = "q";
            s10 = "Q";
            s11 = "m";
            s12 = "M";
            cin >> move;
            if (move == s9 || move == s10)
                return;
            if (move == s11 || move == s12)
                displayMap(grid);
        } while ((move != s1) && (move != s2) && (move != s3) && (move != s4) && (move != s5) && (move != s6) &&
                 (move != s7) && (move != s8));


        if (move == "A" || move == "a") {
            if (lastmovej == 0) {
                cout << "You cannot access this area." << endl;
            } else {
                int check = check_grid(grid[lastmovei][lastmovej - 1]);
                if (check != 0){
                    if (grid[lastmovei][lastmovej] == "M H") grid[lastmovei][lastmovej] = "M";
                    if (grid[lastmovei][lastmovej] == ".H") grid[lastmovei][lastmovej] = ".";

                    lastmovej--;                          //moves the heroes
                    if (check == 1) {                   //if the place is the market
                        for (int i = 0; i < heroes_quantity; i++) {
                            market.market_operate(*heroes[i]);
                        }
                        grid[lastmovei][lastmovej] = "M H";
                    } else {
                        grid[lastmovei][lastmovej] = ".H";
                        battle(heroes, type_of_hero, heroes_quantity);
                    }
                }

            }
        } else if (move == "W" || move == "w") {
            if (lastmovei == 0) {
                cout << "You cannot access this area." << endl;
            } else {
                int check = check_grid(grid[lastmovei - 1][lastmovej]);
                if (check != 0){
                    if (grid[lastmovei][lastmovej] == "M H") grid[lastmovei][lastmovej] = "M";
                    if (grid[lastmovei][lastmovej] == ".H") grid[lastmovei][lastmovej] = ".";

                    lastmovei--;
                    if (check == 1) {
                        for (int i = 0; i < heroes_quantity; i++) {
                            market.market_operate(*heroes[i]);
                        }
                        grid[lastmovei][lastmovej] = "M H";
                    } else {
                        grid[lastmovei][lastmovej] = ".H";
                        battle(heroes, type_of_hero, heroes_quantity);
                    }
                }
            }
        } else if (move == "S" || move == "s") {
            if (lastmovei == 9) {
                cout << "You cannot access this area." << endl;
            } else {
                int check = check_grid(grid[lastmovei + 1][lastmovej]);
                if (check != 0){
                    if (grid[lastmovei][lastmovej] == "M H") grid[lastmovei][lastmovej] = "M";
                    if (grid[lastmovei][lastmovej] == ".H") grid[lastmovei][lastmovej] = ".";

                    lastmovei++;
                    if (check == 1) {
                        for (int i = 0; i < heroes_quantity; i++) {
                            market.market_operate(*heroes[i]);
                        }
                        grid[lastmovei][lastmovej] = "M H";
                    } else {
                        grid[lastmovei][lastmovej] = ".H";
                        battle(heroes, type_of_hero, heroes_quantity);
                    }
                }
            }
        } else if (move == "D" || move == "d") {
            if (lastmovej == 9) {
                cout << "You cannot access this area." << endl;
            } else {
                int check = check_grid(grid[lastmovei][lastmovej + 1]);
                if (check != 0){
                    if (grid[lastmovei][lastmovej] == "M H") grid[lastmovei][lastmovej] = "M";
                    if (grid[lastmovei][lastmovej] == ".H") grid[lastmovei][lastmovej] = ".";

                    lastmovej++;
                    if (check == 1) {
                        for (int i = 0; i < heroes_quantity; i++) {
                            market.market_operate(*heroes[i]);
                        }
                        grid[lastmovei][lastmovej] = "M H";

                    } else {
                        grid[lastmovei][lastmovej] = ".H";
                        battle(heroes, type_of_hero, heroes_quantity);
                    }
                }
            }
        }
    }
}
void displayMap(string** grid){             //printing grid
    int i,j;
    for(i=0;i<10;i++){
        cout<<"# # # # ";
    }
    cout<<"# #"<<endl;
    for(  i=0; i<10; i++){			//print
        for(  j=0; j<10; j++){
            cout<<"|";
            cout<<" "<<grid[i][j]<<"\t   ";
        }
        cout<<"#";

        cout<<endl;
        cout<<endl;
    }
    for(i=0;i<10;i++){
        cout<<"# # # # ";
    }
    cout<<"# #"<<endl;
}