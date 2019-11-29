#include <iostream>
#include <cstdlib>     /* srand, rand */
#include <time.h>       /* time */
#include "Grid.h"
#include "Market.h"
using namespace std;
/*void loading(){
    cout<<"Loading game..."<<endl;
    for(int i=0;i<400000;i++){}
    cout<<"█░░░░░░░░░░░░░░░░░░░░░░░░░░░░  1%"<<endl<<endl;
    for(int i=0;i<300000000;i++){}
    cout<<"███░░░░░░░░░░░░░░░░░░░░░░░░░░ 12%"<<endl<<endl;
    for(int i=0;i<400000000;i++){}
    cout<<"███████░░░░░░░░░░░░░░░░░░░░░░ 28%"<<endl<<endl;
    cout<<"████████░░░░░░░░░░░░░░░░░░░░░ 30%"<<endl<<endl;
    for(int i=0;i<800000000;i++){}
    cout<<"███████████████░░░░░░░░░░░░░░ 50%"<<endl<<endl;
    for(int i=0;i<400000000;i++){}
    cout<<"███████████████░░░░░░░░░░░░░░ 51%"<<endl<<endl;
    for(int i=0;i<400000000;i++){}
    cout<<"███████████████░░░░░░░░░░░░░░ 52%"<<endl<<endl;
    for(int i=0;i<400000000;i++){}
    cout<<"████████████████░░░░░░░░░░░░░ 56%"<<endl<<endl;
    for(int i=0;i<800000000;i++){}
    cout<<"█████████████████████░░░░░░░░ 70%"<<endl<<endl;
    for(int i=0;i<900000000;i++){}
    cout<<"████████████████████████░░░░░ 86%"<<endl<<endl;
    for(int i=0;i<800000000;i++){}
    cout<<"███████████████████████████░░ 90%"<<endl<<endl;
    for(int i=0;i<400000000;i++){}
    cout<<"███████████████████████████░░ 91%"<<endl<<endl;
    for(int i=0;i<400000000;i++){}
    cout<<"███████████████████████████░░ 92%"<<endl<<endl;
    for(int i=0;i<400000000;i++){}
    cout<<"███████████████████████████░░ 93%"<<endl<<endl;
    cout<<"████████████████████████████░ 99%"<<endl<<endl;
    for(int i=0;i<800000000;i++){}
    cout<<"█████████████████████████████ 100%"<<endl<<endl;
    cout<<"Loading Complete."<<endl;
}*/ //Uncomment it for a more realistic experience.
int main() {
    //loading(); //Uncomment it for a more realistic experience.
    srand(time(NULL));
    cout<<"Welcome to the Grid!"<<endl;
    int heroes_quantity;
    Hero **heroes;
    int *type_of_hero;
    do{
        cout<<"Choose how many heroes you want (1-3) and press ENTER."<<endl;
        cin>>heroes_quantity;
        if(heroes_quantity!=1 && heroes_quantity!=2 && heroes_quantity!=3)
            cout<<"You must have at least 1 hero and at most 3 heroes."<<endl;
    }while(heroes_quantity!=1 && heroes_quantity!=2 && heroes_quantity!=3);

    heroes=new Hero*[heroes_quantity];
    type_of_hero=new int[heroes_quantity];

    if(heroes_quantity==1){ //One hero creation
        cout<<"Give a name to your hero."<<endl;
        string name;
        cin>>name;
        int type;
        do{
            cout<<"Choose if your hero is 1.Warrior 2.Sorcerer 3.Paladin. A warrior has increased strength and agility. A sorcerer has increased dexterity and agility. A paladin has increased strength and dexterity."<<endl;
            cin>>type;
            if(type!=1 && type!=2 && type!=3)
                cout<<"Please give a number between 1 and 3 and press ENTER."<<endl;
        }while(type!=1 && type!=2 && type!=3);
        if(type==1) {
            heroes[0] = new Warrior(name, 1, 1000, 1000, 300, 50, 250, 950, 0, 1000);
        }
        if(type==2) {
            heroes[0] = new Sorcerer(name, 1, 1000, 1000, 50, 300, 250, 950, 0, 1000);
        }
        if(type==3) {
            heroes[0] = new Paladin(name, 1, 1000, 1000, 300, 250, 50, 950, 0, 1000);
        }
        type_of_hero[0]=type;
    }


    if(heroes_quantity==2){ //Two heroes creation
        cout<<"Give a name to your first hero."<<endl;
        string name;
        cin>>name;
        int type;
        do{
            cout<<"Choose if your first hero is 1.Warrior 2.Sorcerer 3.Paladin. A warrior has increased strength and agility. A sorcerer has increased dexterity and agility. A paladin has increased strength and dexterity."<<endl;
            cin>>type;
            if(type!=1 && type!=2 && type!=3)
                cout<<"Please give a number between 1 and 3 and press ENTER."<<endl;
        }while(type!=1 && type!=2 && type!=3);

        if(type==1) {
            heroes[0] = new Warrior(name, 1, 1000, 1000, 300, 50, 250, 950, 0, 1000);
        }
        if(type==2) {
            heroes[0] = new Sorcerer(name, 1, 1000, 1000, 50, 300, 250, 950, 0, 1000);
        }
        if(type==3) {
            heroes[0] = new Paladin(name, 1, 1000, 1000, 300, 250, 50, 950, 0, 1000);
        }
        type_of_hero[0]=type;

        cout<<"Give a name to your second hero."<<endl;
        cin>>name;
        do{
            cout<<"Choose if your second hero is 1.Warrior 2.Sorcerer 3.Paladin. A warrior has increased strength and agility. A sorcerer has increased dexterity and agility. A paladin has increased strength and dexterity."<<endl;
            cin>>type;
            if(type!=1 && type!=2 && type!=3)
                cout<<"Please give a number between 1 and 3 and press ENTER."<<endl;
        }while(type!=1 && type!=2 && type!=3);
        if(type==1) {
            heroes[1] = new Warrior(name, 1, 1000, 1000, 300, 50, 250, 950, 0, 1000);
        }
        if(type==2) {
            heroes[1] = new Sorcerer(name, 1, 1000, 1000, 50, 300, 250, 950, 0, 1000);
        }
        if(type==3) {
            heroes[1] = new Paladin(name, 1, 1000, 1000, 300, 250, 50, 950, 0, 1000);
        }
        type_of_hero[1]=type;
    }

    if(heroes_quantity==3){ //Three heroes creation
        cout<<"Give a name to your first hero."<<endl;
        string name;
        cin>>name;
        int type;
        do{
            cout<<"Choose if your first hero is 1.Warrior 2.Sorcerer 3.Paladin. A warrior has increased strength and agility. A sorcerer has increased dexterity and agility. A paladin has increased strength and dexterity."<<endl;
            cin>>type;
            if(type!=1 && type!=2 && type!=3)
                cout<<"Please give a number between 1 and 3 and press ENTER."<<endl;
        }while(type!=1 && type!=2 && type!=3);
        if(type==1)
            heroes[0] = new Warrior(name, 1, 1000, 1000, 300, 50, 250, 950, 0, 1000);
        if(type==2)
            heroes[0] = new Sorcerer(name, 1, 1000, 1000, 50, 300, 250, 950, 0, 1000);

        if(type==3)
            heroes[0] = new Paladin(name,1,1000,1000,300,250,50,950,0,1000);
        type_of_hero[0]=type;
        cout<<"Give a name to your second hero."<<endl;
        cin>>name;
        do{
            cout<<"Choose if your second hero is 1.Warrior 2.Sorcerer 3.Paladin. A warrior has increased strength and agility. A sorcerer has increased dexterity and agility. A paladin has increased strength and dexterity."<<endl;
            cin>>type;
            if(type!=1 && type!=2 && type!=3)
                cout<<"Please give a number between 1 and 3 and press ENTER."<<endl;
        }while(type!=1 && type!=2 && type!=3);
        if(type==1)
            heroes[1] = new Warrior(name,1,1000,1000,300,50,250,950,0,1000);
        if(type==2)
            heroes[1] = new Sorcerer(name,1,1000,1000,50,300,250,950,0,1000);
        if(type==3)
            heroes[1] = new Paladin(name,1,1000,1000,300,250,50,950,0,1000);
        type_of_hero[1]=type;
        cout<<"Give a name to your third hero."<<endl;
        cin>>name;
        do{
            cout<<"Choose if your third hero is 1.Warrior 2.Sorcerer 3.Paladin. A warrior has increased strength and agility. A sorcerer has increased dexterity and agility. A paladin has increased strength and dexterity."<<endl;
            cin>>type;
            if(type!=1 && type!=2 && type!=3)
                cout<<"Please give a number between 1 and 3 and press ENTER."<<endl;
        }while(type!=1 && type!=2 && type!=3);
        if(type==1)
            heroes[2] = new Warrior(name,1,1000,1000,300,50,250,950,0,1000);
        if(type==2)
            heroes[2] = new Sorcerer(name,1,1000,1000,50,300,250,950,0,1000);
        if(type==3)
            heroes[2] = new Paladin(name,1,1000,1000,300,250,50,950,0,1000);
        type_of_hero[2]=type;
    }
    cout<<"Good! Hero creation was completed."<<endl;
    string** Grid;
    Grid=create_grid();
    displayMap(Grid);
    Market market;
    int lastmovei=0;
    int lastmovej=0;
    move(Grid,lastmovei,lastmovej,heroes,type_of_hero,heroes_quantity,market);
    cout<<"Thank you for playing!"<<endl<<endl;
    for(int i=0; i<heroes_quantity; i++)
        delete heroes[i];
    delete[] heroes;
    delete[] type_of_hero;
    cout<<endl;
    return 0;
}


