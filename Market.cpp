#include "Market.h"
void Market::market_buildup(){
    catalogue_of_Items[0]=new Weapon("<=======|==o The Screaming Eagle",450,1,24,1);
    catalogue_of_Items[1]=new Weapon("(|) Limbsplit",500,1,44,2);
    catalogue_of_Items[2]=new Weapon("<=======|==o Lakishu's Blade",550,3,45,1);
    catalogue_of_Items[3]=new Weapon("(|) Hezmana's Bloodlust",1200,4,100,2);
    catalogue_of_Items[4]=new Weapon("|) Nuro's Harp",1500,5,110,2);
    catalogue_of_Items[5]=new Weapon("<=======|==o Ephemeral Edge",2000,7,150,1);
    catalogue_of_Items[6]=new Weapon("<=======|==o Severed in Sleep",2500,8,170,1);
    catalogue_of_Items[7]=new Weapon("<=======|==o Dreamfeather",3000,9,180,2);
    catalogue_of_Items[8]=new Weapon("<=======|==o Starforge",5000,10,190,1);
    catalogue_of_Items[9]=new Weapon("(|) Ragnarok's Breath",5500,10,200,2);

    catalogue_of_Items[10]=new Armor("(|#|) Tabula Rasa",450,1,10);
    catalogue_of_Items[11]=new Armor("(|#|) Thousand Ribbons",600,1,24);
    catalogue_of_Items[12]=new Armor("(|#|) Cloak of Flame",1000,3,35);
    catalogue_of_Items[13]=new Armor("(|#|) Infernal Mantle",1200,4,40);
    catalogue_of_Items[14]=new Armor("(|#|) The Beast Fur Shawl",1500,5,60);
    catalogue_of_Items[15]=new Armor("(|#|) Belly of the Beast",2000,7,89);
    catalogue_of_Items[16]=new Armor("(|#|) Cloak of Defiance",2500,8,120);
    catalogue_of_Items[17]=new Armor("(|#|) Iron Heart",3000,9,180);
    catalogue_of_Items[18]=new Armor("(|#|) Skin of the Lords",5000,10,190);
    catalogue_of_Items[19]=new Armor("(|#|) Guardian Angel",5500,10,200);

    catalogue_of_Items[20]=new Potion("(H) Small Health potion",50,1,150,"Health potion");
    catalogue_of_Items[21]=new Potion("(H) Medium Health potion",150,1,300,"Health potion");
    catalogue_of_Items[22]=new Potion("(H) Big Health potion",250,3,500,"Health potion");
    catalogue_of_Items[23]=new Potion("(M) Small Magic potion",50,1,150,"Magic potion");
    catalogue_of_Items[24]=new Potion("(M) Medium Magic potion",150,1,300,"Magic potion");
    catalogue_of_Items[25]=new Potion("(M) Big Magic potion",250,3,500,"Magic potion");
    catalogue_of_Items[26]=new Potion("(S) Small Strength potion",50,5,70,"Strength Potion");
    catalogue_of_Items[27]=new Potion("(S) Medium Strength potion",250,9,140,"Strength Potion");
    catalogue_of_Items[28]=new Potion("(D) Dexterity potion",350,1,150,"Dexterity Potion");
    catalogue_of_Items[29]=new Potion("(A) Agility potion",350,1,200,"Agility Potion");


    catalogue_of_Spells[0]=new FireSpell("(F) Curse of the sun",450,1,30,10);
    catalogue_of_Spells[1]=new FireSpell("(F) Hellfire",550,3,70,30);
    catalogue_of_Spells[2]=new FireSpell("(F) Devil's Breath",1000,5,150,70);

    catalogue_of_Spells[3]=new IceSpell("(I) Icebolt",450,1,15,5);
    catalogue_of_Spells[4]=new IceSpell("(I) North Wind",550,3,30,10);
    catalogue_of_Spells[5]=new IceSpell("(I) Ice Spike",1000,5,100,60);

    catalogue_of_Spells[6]=new LightingSpell("(L) Electric Arrow",450,1,25,8);
    catalogue_of_Spells[7]=new LightingSpell("(L) Charged Raven",550,3,130,60);
    catalogue_of_Spells[8]=new LightingSpell("(L) Zeus' Charge",1000,5,140,80);
}

void Market::market_operate(Hero& hero){
    cout<<"Welcome to the Market! What would you like to see "<<hero.get_name()<<"?"<<endl;
    cout<<"                          __________\n"
            "                      .~#########%%;~.\n"
            "                     /############%%;`\\\n"
            "                    /######/~\\/~\\%%;,;,\\\n"
            "                   |#######\\    /;;;;.,.|\n"
            "                   |#########\\/%;;;;;.,.|\n"
            "          XX       |##/~~\\####%;;;/~~\\;,|       XX\n"
            "        XX..X      |#|  o  \\##%;/  o  |.|      X..XX\n"
            "      XX.....X     |##\\____/##%;\\____/.,|     X.....XX\n"
            " XXXXX.....XX      \\#########/\\;;;;;;,, /      XX.....XXXXX\n"
            "X |......XX%,.@      \\######/%;\\;;;;, /      @#%,XX......| X\n"
            "X |.....X  @#%,.@     |######%%;;;;,.|     @#%,.@  X.....| X\n"
            "X  \\...X     @#%,.@   |# # # % ; ; ;,|   @#%,.@     X.../  X\n"
            " X# \\.X        @#%,.@                  @#%,.@        X./  #\n"
            "  ##  X          @#%,.@              @#%,.@          X   #\n"
            ", \"# #X            @#%,.@          @#%,.@            X ##\n"
            "   `###X             @#%,.@      @#%,.@             ####'\n"
            "  . ' ###              @#%.,@  @#%,.@              ###`\"\n"
            "    . \";\"                @#%.@#%,.@                ;\"` ' .\n"
            "      '                    @#%,.@                   ,.\n"
            "      ` ,                @#%,.@  @@                `\n"
            "                          @@@  @@@  "<<endl;
    int w,temp;
    do{
        cout<<"Press 1 to see the weapons for sale, 2 to see the armors for sale, 3 to see the potions for sale and 4 to see the spells for sale."<<endl;
        cout<<"Press 5 to sell your items and spells."<<endl;
        cout<<"Press 0 to quit the market."<<endl;
        cin>>w;
        if(w!=1 && w!=2 && w!=3 && w!=4 && w!=5 && w!=0){
            cout<<"What did you said you want???"<<endl;
        }
        if(w==1){ //Weapons
            cout<<"Choose your weapon!"<<endl;
            for(int i=0; i<10; i++){
                cout<<i+1<<".";
                cout<<catalogue_of_Items[i]->get_name()<<" with damage "<<catalogue_of_Items[i]->get_damage()<<" requires "<<catalogue_of_Items[i]->get_hands()<<" hand(s).";
                cout<<" Price: "<<catalogue_of_Items[i]->get_price()<<"  Minimum Level required to be equipped: "<<catalogue_of_Items[i]->get_min_level()<<endl;
            }
            do{
                cout<<"Press a number between 1-10 to buy the equivelant weapon or press 0 to stop buying weapons and return to the menu."<<endl;
                cin>>temp;
                if(temp>=1 && temp<=10){
                    if(catalogue_of_Items[temp-1]->get_price()<=hero.get_money()){ // -1 because table starts from 0
                        hero.put_in_inventory(catalogue_of_Items[temp-1]);
                    }else
                        cout<<"You don't have enough money to buy the weapon "<<catalogue_of_Items[temp-1]->get_name()<<"."<<endl;
                }
            }while(temp!=0);
        }
        if(w==2){ //Armors
            cout<<"Choose your armor!"<<endl;
            for(int i=10; i<20; i++){
                cout<<i-9<<".";
                cout<<catalogue_of_Items[i]->get_name()<<" with defense rate "<<catalogue_of_Items[i]->get_armor()<<".";
                cout<<" Price: "<<catalogue_of_Items[i]->get_price()<<"  Minimum Level required to be equipped: "<<catalogue_of_Items[i]->get_min_level()<<endl;
            }
            do{
                cout<<"Press a number between 1-10 to buy the equivelant armor or press 0 to stop buying armors and return to the menu."<<endl;
                cin>>temp;
                if(temp>=1 && temp<=10){
                    if(catalogue_of_Items[temp+9]->get_price()<=hero.get_money()){ //We need to add 10-1 to get the correct item
                        hero.put_in_inventory(catalogue_of_Items[temp+9]);
                    }else
                        cout<<"You don't have enough money to buy the armor "<<catalogue_of_Items[temp+9]->get_name()<<"."<<endl;
                }
            }while(temp!=0);
        }
        if(w==3){ //Potions
            cout<<"Choose your potion!"<<endl;
            for(int i=20; i<30; i++){
                cout<<i-19<<".";
                cout<<catalogue_of_Items[i]->get_name()<<" is a "<<catalogue_of_Items[i]->get_type()<<" which restores "<<catalogue_of_Items[i]->get_rate()<<".";
                cout<<" Price: "<<catalogue_of_Items[i]->get_price()<<"  Minimum Level required to be equipped: "<<catalogue_of_Items[i]->get_min_level()<<endl;
            }
            do{
                cout<<"Press a number between 1-10 to buy the equivelant potion or press 0 to stop buying potions and return to the menu."<<endl;
                cin>>temp;
                if(temp>=1 && temp<=10){
                    if(catalogue_of_Items[temp+19]->get_price()<=hero.get_money()){ //We need to add 20-1 to get the correct item
                        hero.put_in_inventory(catalogue_of_Items[temp+19]);
                    }else
                        cout<<"You don't have enough money to buy the potion "<<catalogue_of_Items[temp+19]->get_name()<<"."<<endl;
                }
            }while(temp!=0);
        }
        if(w==4){ //Spells
            cout<<"Choose your spells!"<<endl;
            for(int i=0; i<9; i++){
                cout<<i+1<<".";
                cout<<catalogue_of_Spells[i]->get_name()<<" with damage "<<catalogue_of_Spells[i]->get_damage()<<" and magic power cost "<<catalogue_of_Spells[i]->get_magic_power_cost()<<".";
                cout<<" Price: "<<catalogue_of_Spells[i]->get_price()<<"  Minimum Level required to be equipped: "<<catalogue_of_Spells[i]->get_level_required()<<endl;
            }
            do{
                cout<<"Press a number between 1-10 to buy the equivelant spell or press 0 to stop buying spells and return to the menu."<<endl;
                cin>>temp;
                if(temp>=1 && temp<=10){
                    if(catalogue_of_Spells[temp-1]->get_price()<=hero.get_money()){ //We need to add 20-1 to get the correct item
                        hero.put_in_spells(catalogue_of_Spells[temp-1]);
                    }else
                        cout<<"You don't have the money to buy the spell"<<catalogue_of_Spells[temp-1]->get_name()<<"."<<endl;
                }
            }while(temp!=0);
        }
        if(w==5){ //Sell
            cout<<"Sell your items!"<<endl;
            if(hero.checkInventory(false)!=-1){ //Empty Inventory
                do{
                    cout<<"Press a number between 1-10 to sell the equivelant item or press 0 to stop selling items."<<endl;
                    cin>>temp;
                    if(temp>=1 && temp<=10){
                        hero.sell_from_inventory(temp-1);
                    }
                }while(temp!=0 && hero.checkInventory(false)!=-1);
            }
            cout<<"Sell your spells!"<<endl;
            if(hero.checkSpells()!=-1) { //Empty Spells
                do {
                    cout
                            << "Press a number between 1-3 to sell the equivelant spell or press 0 to stop selling spells and return to the menu."
                            << endl;
                    cin >> temp;
                    if (temp >= 1 && temp <= 3) {
                        hero.sell_from_spells(temp - 1);
                    }
                } while (temp != 0 && hero.checkSpells()!=-1);
            }
        }
    }while(w!=0);
    cout<<"Thank you for visiting the market!"<<endl;
}