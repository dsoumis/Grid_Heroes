#include "Battlefield.h"
void display_stats(Hero *heroes[],Monster *monsters[],const int& heroes_quantity,const int& monsters_quantity){
    for(int i=0; i<heroes_quantity; i++){
        cout<<"Hero "<<heroes[i]->get_name()<<" is level "<<heroes[i]->get_level()<<", with current health "<<heroes[i]->get_hp()<<"."<<endl;
        cout<<heroes[i]->get_name()<<" has "<<heroes[i]->get_magicPower()<<" magic power, "<<heroes[i]->get_strength()<<" strength, "<<heroes[i]->get_dexterity()<<" dexterity, "<<heroes[i]->get_agility()<<" agility, "<<heroes[i]->get_weapon_damage()<<" weapon damage, and "<<heroes[i]->get_defense()<<" defense."<<endl;
        cout<<"Money: "<<heroes[i]->get_money()<<"."<<endl;
    }
    for(int i=0; i<monsters_quantity; i++){
        cout<<"Monster "<< monsters[i]->get_name()<<" is at "<<monsters[i]->get_level()<<" level with current health "<<monsters[i]->get_hp()<<" ,"<<monsters[i]->get_attack_damage()<<" attack damage ,"<<monsters[i]->get_defense()<<" defense and "<<monsters[i]->get_escape_probability()<<"% escape probability."<<endl;
    }
}
bool battle_probability(){
    return (rand() % 100) < 40; //The probability of beginning a battle is 40%.
}
int hero_attack(Hero& hero, Monster& monster){
    int attack_choosing;
    while(true) {
        cout << "Choose if you want " << hero.get_name() << " to 1.physically attack,2.cast a spell or 3.to use an item from inventory by pressing the equivalent number and then ENTER" << endl;
        do {
            cin >> attack_choosing;
        } while (attack_choosing != 1 && attack_choosing != 2 && attack_choosing != 3);

        if (attack_choosing == 1) {
            if(hero.attack(monster)!=-1){
                return -1;
            }
        }
        if (attack_choosing == 2) {
            int temp;
            temp=hero.castSpell(monster);
            if(temp!=-1){
                return temp;  //Returns the rounds that a spell has effect
            }
        }
        if (attack_choosing == 3) {
            if(hero.checkInventory(true)!=-1)
                return -1;
        }
    }
}
void resuming_stats(int& resume_at_round,int& type_of_magic,bool& used,Monster& monster,const int& round){ //When the effects of spells wear off..
    if (resume_at_round == round) {
        if(type_of_magic==1) {
            monster.resume_damage(200);
            cout << "Resuming " << monster.get_name() << "'s damage." << endl;
        }
        else if(type_of_magic==2) {
            monster.resume_defense(100);
            cout << "Resuming " << monster.get_name() << "'s defense." << endl;
        }
        else if(type_of_magic==3) {
            monster.resume_escape_probability(50);
            cout << "Resuming " << monster.get_name() << "'s escapeprobability." << endl;
        }
        used = false;
    }
}
void ifheroes_won(const Monster& monster,Hero *heroes[],int type_of_hero[],const int& length){ //Prints which monster(s) died and levels up heroes.
    if (monster.get_hp() <= 0) {
        if(length!=1)
            cout << "Heroes have killed the "<<monster.get_name()<<"!" << endl;
        else
            cout << "Hero has killed the "<<monster.get_name()<<"!" << endl;
        if(monster.get_name()=="Dragon"){
            for(int i=0; i<length; i++){
                heroes[i]->increase_experience(1000);
                heroes[i]->levelUp(type_of_hero[i]);
            }
        }else if(monster.get_name()=="Exoskeleton"){
            monster.get_name()="Dead Exoskeleton"; //In order not to enter again and gain more experience
            for(int i=0; i<length; i++){
                heroes[i]->increase_experience(1000);
                heroes[i]->levelUp(type_of_hero[i]);
            }
        }else if(monster.get_name()=="Spirit"){
            monster.get_name()="Dead Spirit";
            for(int i=0; i<length; i++){
                heroes[i]->increase_experience(1000);
                heroes[i]->levelUp(type_of_hero[i]);
            }
        }
    }
}

const Monster& hero_select(Hero& h1,Monster& monster,int& rounds_of_spell,bool& used_hero,bool used[3],int resume_at_round[3],int type_of_magic[3],int& round){
        rounds_of_spell = hero_attack(h1, monster);
        used_hero = true; //The first hero has attacked so the player must choose another hero for the next attack if they are not used also
        if (rounds_of_spell != -1) {
            if (!used[0]) {
                resume_at_round[0] = round + rounds_of_spell;
                type_of_magic[0]=rounds_of_spell; //From the rounds that the spell exists we understand if it is a Fire/Ice/Lightning spell
                used[0] = true;
            } else if (used[0] && !used[1]) {
                resume_at_round[1] = round + rounds_of_spell;
                type_of_magic[1]=rounds_of_spell;
                used[1] = true;
            } else if (used[0] && used[1] && !used[2]) {
                resume_at_round[2] = round + rounds_of_spell;
                type_of_magic[2]=rounds_of_spell;
                used[2] = true;
            }
        }
        return monster;
}
int choose_hero(Hero *heroes[],bool used_hero[],const int& heroes_quantity,Monster *monsters[],const int monsters_quantity){
    int hero_selection;
    if(heroes_quantity==3) {
        cout << "Choose a hero to attack  by pressing 1,2 or 3 (or 4 to display stats) and then ENTER." << endl;
        do {
            cin >> hero_selection;
            if ((hero_selection == 1 && used_hero[0]) || (hero_selection == 2 && used_hero[1]) || (hero_selection == 3 && used_hero[2])) {
                cout << "You have already played with this player." << endl;
                hero_selection = -1;
            }
            if ((hero_selection == 1 || hero_selection == 2 || hero_selection == 3) &&
                (heroes[0]->get_hp() <= 0 || heroes[1]->get_hp() <= 0 || heroes[2]->get_hp() <= 0)) {
                cout << heroes[hero_selection - 1]->get_name() << " has fainted so obviously can't attack." << endl;
                hero_selection = -1;
            }
            if (hero_selection == 4) {
                display_stats(heroes,monsters,heroes_quantity,monsters_quantity);
                cout << "Choose a hero to attack  by pressing 1,2 or 3 and then ENTER." << endl;
            }
        } while (hero_selection != 1 && hero_selection != 2 && hero_selection != 3);
    }else if(heroes_quantity==2){
        cout << "Choose a hero to attack  by pressing 1 or 2 (or 4 to display stats) and then ENTER." << endl;
        do {
            cin >> hero_selection;
            if ((hero_selection == 1 && used_hero[0]) || (hero_selection == 2 && used_hero[1])) {
                cout << "You have already played with this player." << endl;
                hero_selection = -1;
            }
            if ((hero_selection == 1 || hero_selection == 2 ) && (heroes[0]->get_hp() <= 0 || heroes[1]->get_hp() <= 0)) {
                cout << heroes[hero_selection - 1]->get_name() << " has fainted so obviously can't attack." << endl;
                hero_selection = -1;
            }
            if (hero_selection == 4) {
                display_stats(heroes,monsters,heroes_quantity,monsters_quantity);
                cout << "Choose a hero to attack  by pressing 1 or 2 and then ENTER." << endl;
            }
        } while (hero_selection != 1 && hero_selection != 2);
    }else if(heroes_quantity==1){
        cout << "Choose the hero to attack  by pressing 1  (or 4 to display stats) and then ENTER." << endl;
        do {
            cin >> hero_selection;
            if (hero_selection == 4) {
                display_stats(heroes,monsters,heroes_quantity,monsters_quantity);
                cout << "Choose the hero to attack  by pressing 1 and then ENTER." << endl;
            }
        } while (hero_selection != 1 );
    }

    return hero_selection;
}
int choose_monster(Monster *monsters[]){
    int monster_selection;
    cout << "Choose a monster to attack  by pressing 1,2 or 3 and then ENTER." << endl;
    do {
        cin >> monster_selection;
        if ((monster_selection == 1 && monsters[0]->get_hp()<=0) || (monster_selection == 2 && monsters[1]->get_hp()<=0) || (monster_selection == 3 && monsters[2]->get_hp()<=0)) {
            cout << "This monster is already dead." << endl;
            monster_selection = -1;
        }
    } while (monster_selection != 1 && monster_selection != 2 && monster_selection != 3);
    return monster_selection;
}
void monster_attacks_hero(Monster& monster,Hero *heroes[],const int& heroes_quantity){
    if(monster.get_hp()>0) {
        if (heroes_quantity == 1)
            monster.attack_hero(*heroes[0]);
        else {
            int random_hero;
            random_hero = rand() % heroes_quantity; //Randomly attack a hero
            monster.attack_hero(*heroes[random_hero]);
        }
    }
}
void vote_zero(Hero *heroes[],int type_of_hero[],const int& heroes_quantity){
    Monster **monsters;
    monsters=new Monster*[1];
    monsters[0]=new Dragon("Dragon",heroes[0]->get_level(),1500,200+heroes[0]->get_level()*2,200,20);

    cout<<"Get ready for a fight!"<<endl;
    int hero_selection,round,rounds_of_spell,resume_at_round[heroes_quantity][3],type_of_magic[heroes_quantity][3];
    bool used_resume[heroes_quantity][3],used_hero[heroes_quantity];
    for(int i=0; i<heroes_quantity; i++) {
        used_hero[i]=false; //This is used in order not to allow the player to play again with the same hero
        for (int j = 0; j < 3; j++) {
            used_resume[i][j] = false; /*A counter for the rounds that helps resuming the stats. It has 3 places for every hero because tha max spell effects occurs for 3 rounds so if the first spell at round 1
                                        has an effect of 3 rounds it should resume at round 3. Then a second spell at round 2 with 3 rounds effect should resume at round 4. After the third spell
                                        we use again the first place because as said before the max round effect is 3 rounds.We would lose the rounds that stats should be resumed without this table.*/
            resume_at_round[i][j] = -1; //It holds the rounds that resuming of stats shall happen
        }
    }
    bool stop=false;
    round=0; //First round
    while(monsters[0]->get_hp()>0 && !stop){
        cout<<"Round "<<round+1<<"!"<<endl;
        for(int i=0; i<heroes_quantity; i++) {
            hero_selection=choose_hero(heroes,used_hero,heroes_quantity,monsters,1);

            hero_select(*heroes[hero_selection-1],*monsters[0],rounds_of_spell,used_hero[hero_selection-1],used_resume[hero_selection-1],resume_at_round[hero_selection-1],type_of_magic[hero_selection-1],round); //Pass the first row of two-dimensional arrays


            ifheroes_won(*monsters[0],heroes,type_of_hero,heroes_quantity);
        }
        for(int i=0; i<heroes_quantity; i++){ //Checks everytime if it is a round for resuming stats
            for(int j=0; j<3; j++){
                resuming_stats(resume_at_round[i][j],type_of_magic[i][j],used_resume[i][j],*monsters[0],round);
            }
        }
        monster_attacks_hero(*monsters[0],heroes,heroes_quantity);
        int temp=0;
        for(int i=0; i<heroes_quantity; i++){//After the end of each round
            used_hero[i]=false; //You can use i hero again
            if(heroes[i]->get_hp()<=0)
                temp++;
        }
        if(temp==heroes_quantity) //If all heroes have died
            stop=true;
        round++;
    }
    cout<<"End of the fight."<<endl;
    delete monsters[0];
    delete[] monsters;
}
void vote_one(Hero *heroes[],int type_of_hero[],const int& heroes_quantity){
    Monster **monsters;
    monsters=new Monster*[3];
    monsters[0]=new Exoskeleton("Exoskeleton_1",heroes[0]->get_level(),1000,100,500+heroes[0]->get_level()*2,10);
    monsters[1]=new Exoskeleton("Exoskeleton_2",heroes[0]->get_level(),1000,100,500+heroes[0]->get_level()*2,10);
    monsters[2]=new Spirit("Spirit",heroes[0]->get_level(),100,150,0,20+heroes[0]->get_level());

    cout<<"Get ready for a fight!"<<endl;
    int hero_selection,monster_selection,round,rounds_of_spell,resume_at_round[heroes_quantity][3],type_of_magic[heroes_quantity][3],rounding_attack[heroes_quantity];
    bool used_resume[heroes_quantity][3],used_hero[heroes_quantity];
    Monster monster_pointers[heroes_quantity][3];
    for(int i=0; i<heroes_quantity; i++) {
        used_hero[i]=false;
        rounding_attack[i]=0; //An extra help as used_resume (as described in function vote zero) because here we have 3 monsters
        for (int j = 0; j < 3; j++) {
            used_resume[i][j] = false;
            resume_at_round[i][j] = -1;
        }
    }
    bool stop=false;
    round=0; //First round
    while( (monsters[0]->get_hp()>0 || monsters[1]->get_hp()>0 || monsters[2]->get_hp()>0) && !stop){
        cout<<"Round "<<round+1<<"!"<<endl;
        for(int i=0; i<heroes_quantity; i++) {
            hero_selection=choose_hero(heroes,used_hero,heroes_quantity,monsters,3);
            monster_selection=choose_monster(monsters);

            monster_pointers[i][rounding_attack[i]]=hero_select(*heroes[hero_selection-1],*monsters[monster_selection-1],rounds_of_spell,used_hero[hero_selection-1],used_resume[hero_selection-1],resume_at_round[hero_selection-1],type_of_magic[hero_selection-1],round);
            //^saves the monster that was attacked. The columns of the array are made by rounding_attack of a hero because we want for each hero to start from zero and in next round to continue from the correct value
            rounding_attack[i]++;
            if(rounding_attack[i]==3) rounding_attack[i]=0;
            for(int j=0; j<3; j++)
                ifheroes_won(*monsters[j], heroes, type_of_hero, heroes_quantity);
        }
        for(int i=0; i<heroes_quantity; i++){
            for(int j=0; j<3; j++){
                if(monster_pointers[i][j].get_name()==monsters[0]->get_name()) //In this function resuming stats is called by checking if the name of the monster is the same with the table's
                    resuming_stats(resume_at_round[i][j], type_of_magic[i][j], used_resume[i][j], *monsters[0], round);
                else if (monster_pointers[i][j].get_name()==monsters[1]->get_name())
                    resuming_stats(resume_at_round[i][j], type_of_magic[i][j], used_resume[i][j], *monsters[1], round);
                else if (monster_pointers[i][j].get_name()==monsters[2]->get_name())
                    resuming_stats(resume_at_round[i][j], type_of_magic[i][j], used_resume[i][j], *monsters[2], round);
            }
        }
        for(int i=0; i<3; i++)
            monster_attacks_hero(*monsters[i],heroes,heroes_quantity);
        int temp=0;
        for(int i=0; i<heroes_quantity; i++){
            used_hero[i]=false; //You can use i hero again
            if(heroes[i]->get_hp()<=0)
                temp++;
        }
        if(temp==heroes_quantity)
            stop=true;
        round++;
    }
    cout<<"End of the fight."<<endl;
    delete monsters[0];
    delete monsters[1];
    delete monsters[2];
    delete[] monsters;
}
void battle(Hero *heroes[],int type_of_hero[],const int& heroes_quantity){
    if(battle_probability()){ //If true, there will be a battle
        cout<<"Heroes have encountered monsters!"<<endl;
        int vote;
        vote=rand()%2;
        if(vote==0){//Create Dragon
            vote_zero(heroes,type_of_hero,heroes_quantity);
        }else{ //Create two Exoskeletons and a Spirit
            vote_one(heroes,type_of_hero,heroes_quantity);
        }

    }
}