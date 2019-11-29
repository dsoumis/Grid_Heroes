#include "Livings.h"
Living::Living(string n, int l, int hp): name(n),level(l),healthPower(hp),maxHealth(hp){
    cout<<"A living being with name "<<name<<" has been teleported to the GRID."<<name<<" is level "<<level<<". Ready for battle with "<<healthPower<<" HP points."<<endl;
}
void Living::health_from_damage(double attack){ //Reduces the health of the living being from the attack and prints if the living being has fainted
    healthPower-=attack;
    if(healthPower<=0){
        cout<<name<<" has fainted."<<endl;
        healthPower=0;
    }
}
void Living::increase_level(){
    level++;
    cout<<name<<" has reached level "<<level<<"!"<<endl;
}
int Living::get_level()const{ return level;}
string Living::get_name()const{ return name;}
int Living::get_hp()const{ return healthPower;}
void Living::increase_hp(int r){
    healthPower+=r;
    if(healthPower>maxHealth) //Not overcome the max health when using a health potion
        healthPower=maxHealth;
    cout<<"Current HP points of "<<get_name()<<" : "<<healthPower<<endl;
}


Hero::Hero(string n, int l, int hp, int mp, int s, int d, int a, int m, int exp,int alv):Living(n,l,hp),magicPower(mp),strength(s),dexterity(d),agility(a),money(m),experience(exp),adaptive_leveling_value(alv),maxMagic(mp) {
    cout<<get_name()<<" is a Hero with magic power "<<magicPower<<" strength "<<strength<<" dexterity "<<dexterity<<" agility "<<agility<<" money "<<money<<" and experience "<<experience<<"."<<endl;
    inventory_place=0;
    spell_place=0;
    equipped_armor=-1;
    equipped_left_weapon=-1;
    equipped_right_weapon=-1;
    equipped_two_hands_weapon=-1;
    defense=0;
    Inventory=new Item_List;
    Spells=new Spell_List;
}
Hero::~Hero(){{
        cout<<"and returned peacefully ";
        for(int i=0; i<inventory_place; i++) //Deleting the lists
            Inventory->Delete_from_pos(i);
        for(int i=0; i<spell_place; i++)
            Spells->Delete_from_pos(i);
    }}
int Hero::get_magicPower()const{ return magicPower;};
int Hero::get_strength()const{ return strength;};
int Hero::get_dexterity()const{ return dexterity;};
int Hero::get_money() const{ return money;};
int Hero::get_agility()const{ return agility;};
int Hero::get_defense()const{ return defense;};
int Hero::get_weapon_damage()const{
    if(equipped_two_hands_weapon != -1){
        return Inventory->use(equipped_two_hands_weapon)->get_damage();
    }else{

        if(equipped_left_weapon != -1 && equipped_right_weapon != -1)
            return Inventory->use(equipped_left_weapon)->get_damage()+Inventory->use(equipped_right_weapon)->get_damage();

        else if(equipped_left_weapon == -1 && equipped_right_weapon != -1)
            return Inventory->use(equipped_right_weapon)->get_damage();

        else if(equipped_left_weapon != -1 && equipped_right_weapon == -1)
            return Inventory->use(equipped_left_weapon)->get_damage();

        else if(equipped_left_weapon == -1 && equipped_right_weapon == -1)
            return 0;
    }
}

bool Hero::escaped_the_attack()const{
    return (rand() % 1000) < agility; //The probability of escaping the attack is agility%. For example if agility==75 then the probability of escaping the attack is 75%.
};
void Hero::levelUp(int type){
    if(experience>=adaptive_leveling_value && this->get_level()<10){ //Max 10 level living beings
        cout<<get_name()<<" has leveled up!"<<endl;
        int strength_increase_value,dexterity_increase_value,agility_increase_value;
        if(type==1){ //Warrior
            strength_increase_value=10;
            dexterity_increase_value=2;
            agility_increase_value=12;
        }
        if(type==2){ //Sorcerer
            strength_increase_value=1;
            dexterity_increase_value=14;
            agility_increase_value=11;
        }
        if(type==3){ //Paladin
            strength_increase_value=9;
            dexterity_increase_value=10;
            agility_increase_value=3;
        }
        this->increase_level();
        experience-=adaptive_leveling_value; //Experience which remains for the next level-up
        strength+=strength_increase_value+(adaptive_leveling_value/1000); //Strength/Dexterity/Agility increase each time depending of the type of hero + the adaptive leveling value divided by 1000
        dexterity+=dexterity_increase_value+(adaptive_leveling_value/1000);
        agility=agility_increase_value+(adaptive_leveling_value/1000);
        adaptive_leveling_value+=1000; //Increase the value to reach is level by 1000. To clarify: the first level requires 1000 experience points,the second level requires 2000 experience points,the third 3000...
    }
}
void Hero::decrease_magicPower(int cost){ //When a spell is used
    cout<<"Magic power of "<<get_name()<<" has been decreased from "<<magicPower<<" to ";
    magicPower-=cost;
    cout<<magicPower<<"."<<endl;
}

void Hero::increase_health(int rate){
    Living::increase_hp(rate);
}
void Hero::increase_magicPower(int rate){
    magicPower+=rate;
    if(magicPower>maxMagic)
        magicPower=maxMagic;
}
void Hero::increase_strength(int rate){
    strength+=rate;
}
void Hero::increase_dexterity(int rate){
    dexterity+=rate;
}
void Hero::increase_agility(int rate){
    agility+=rate;
}
void Hero::increase_experience(int rate){
    experience+=rate;
}


void Hero::put_in_inventory(Item* item){
    if(inventory_place<10){ //Heroes can have 10 items to their inventory
        money-=item->get_price();
        Inventory->insert_last(item);
        cout<<"You have acquired the "<<item->get_name()<<"."<<endl;
        inventory_place++;
    } else
        cout<<get_name()<<"'s inventory is full."<<endl;
}
void Hero::put_in_spells(Spell* spell){
    if(spell_place<3){ //Heroes can have 3 spells
        money-=spell->get_price();
        Spells->insert_last(spell);
        cout<<"You have acquired the "<<spell->get_name()<<"."<<endl;
        spell_place++;
    } else
        cout<<"No more spells can be added."<<endl;
}
int Hero::checkInventory(bool equip){ //If bool is false the function only shows the items. Else, items can also be equipped.
    cout<<get_name()<<"'s inventory:"<<endl;
    if(Inventory->Print_name()==-1)
        return -1; //Returns that the inventory is empty
    if(inventory_place>0 && equip){ //At least one item
        int number;
        short int count=0;
        do{
            if(count==0) //In order not to print the inventory again at first time.
                count=1;
            else
                Inventory->Print_name();
            cout<<"Press the equivelant number(s) and then ENTER to equip/use an item or press 0 to exit the inventory."<<endl;
            cin>>number;
            if(number-1>=0 && number-1<=inventory_place){
                equip_from_inventory(number-1);
            }
        }while(number!=0);
    }
}
int Hero::checkSpells()const{
    cout<<get_name()<<"'s spells:"<<endl;
    if(Spells->Print_name()==-1)
        return -1;
}
void Hero::sell_from_inventory(int no){
    money+=((Inventory->use(no))->get_price())/2; //Items are sold at half price
    Inventory->Delete_from_pos(no);
    inventory_place--;
}
void Hero::sell_from_spells(int no){
    money+=((Spells->use(no))->get_price())/2; //Spells are sold at half price
    Spells->Delete_from_pos(no);
    spell_place--;
}


void Hero::usePotion(int no){
    if((Inventory->use(no))->get_type()=="Health potion"){
        increase_health((Inventory->use(no))->get_rate()); //Increase the health by the potion
        Inventory->Delete_from_pos(no); //then delete it from the list
        inventory_place--; //there's a free space for another item now
        return;
    }
    if((Inventory->use(no))->get_type()=="Magic Potion") {
        increase_magicPower((Inventory->use(no))->get_rate());
        Inventory->Delete_from_pos(no);
        inventory_place--;
        return;
    }
    if((Inventory->use(no))->get_type()=="Strength Potion"){
        increase_strength((Inventory->use(no))->get_rate());
        Inventory->Delete_from_pos(no);
        inventory_place--;
        return;
    }
    if((Inventory->use(no))->get_type()=="Dexterity Potion"){
        increase_dexterity((Inventory->use(no))->get_rate());
        Inventory->Delete_from_pos(no);
        inventory_place--;
        return;
    }
    if((Inventory->use(no))->get_type()=="Agility Potion"){
        increase_agility((Inventory->use(no))->get_rate());
        Inventory->Delete_from_pos(no);
        inventory_place--;
        return;
    }
}
void Hero::equip_armor(int no){
    if(equipped_armor==no){
        cout<<Inventory->use(equipped_armor)->get_name()<<" has already been equipped."<<endl;
        return;
    }
    if(equipped_armor!=-1)
        defense-=(Inventory->use(equipped_armor))->get_armor(); //Remove the old armor
    defense+=(Inventory->use(no))->get_armor();
    equipped_armor=no;
    cout<<"Armor "<<Inventory->use(equipped_armor)->get_name()<<" has been equipped."<<endl;
}
void Hero::equip_weapon(int no){
    if( (Inventory->use(no))->get_hands()==2 ){
        equipped_two_hands_weapon=no;
        equipped_left_weapon=-1; //No one-hand weapons
        equipped_right_weapon=-1;
        cout<<Inventory->use(no)->get_name()<<" has been equipped to both hands."<<endl;
    }else{
        equipped_two_hands_weapon=-1;//No two-hands weapons
        if( ((equipped_left_weapon!=-1 || equipped_left_weapon==-1) && equipped_right_weapon!=-1) || (equipped_left_weapon==-1 && equipped_right_weapon==-1) ) { //if Empty or full hands or Empty left Hand
            if(equipped_right_weapon!=no) { //In order not to use the same item
                equipped_left_weapon = no;
                cout << Inventory->use(no)->get_name() << " has been equipped to left hand." << endl;
            } else
                cout<< Inventory->use(no)->get_name() << " has been equipped already to right hand." << endl;
        }
        else if(equipped_right_weapon==-1 && equipped_left_weapon!=-1) { //if Empty right hand
            if(equipped_left_weapon!=no) { //In order not to use the same item
                equipped_right_weapon = no;
                cout << Inventory->use(no)->get_name() << " has been equipped to right hand." << endl;
            } else
                cout<< Inventory->use(no)->get_name() << " has been equipped already to left hand." << endl;
        }
    }
}
void Hero::equip_from_inventory(int no){
    if((Inventory->use(no))->get_min_level()<=this->get_level()) { //If the item's level matches
        if ((((Inventory->use(no))->get_name()).compare(0, 12, "<=======|==o") == 0 || //Checks if it is a weapon,
             ((Inventory->use(no))->get_name()).compare(0, 2, "|)") == 0 ||
             ((Inventory->use(no))->get_name()).compare(0, 3, "(|)") == 0)) {
            equip_weapon(no);
        }
        if ((((Inventory->use(no))->get_name()).compare(0, 5, "(|#|)") == 0)) { //an armor or
            equip_armor(no);
        }
        if (((Inventory->use(no))->get_name()).compare(0, 3, "(H)") == 0 || //a potion.
            ((Inventory->use(no))->get_name()).compare(0, 3, "(M)") == 0 ||
            ((Inventory->use(no))->get_name()).compare(0, 3, "(S)") == 0
            || ((Inventory->use(no))->get_name()).compare(0, 3, "(D)") == 0 ||
            ((Inventory->use(no))->get_name()).compare(0, 3, "(A)") == 0) {
            usePotion(no);
        }
    }else cout<<"This item requires "<<Inventory->use(no)->get_min_level()<<" to be used, but "<<this->get_name()<<" is level "<<this->get_level()<<endl;
}

int Hero::useSpell(int no,Monster& monster){
    if(get_level()>=Spells->use(no)->get_level_required() && get_magicPower()>=Spells->use(no)->get_magic_power_cost()){ //If the spell's level matches and hero has enough magic power to cast it
        int attack=Spells->use(no)->get_damage()+(get_dexterity()/100)*Spells->use(no)->get_damage(); //Dexterity increases the attack
        monster.decrease_defense(attack); //Attack monster
        decrease_magicPower(Spells->use(no)->get_magic_power_cost());

        if(((Spells->use(no))->get_name()).compare(0,3,"(F)")==0){ //Special effect of Firespell
            monster.decrease_only_defense(100);
            return 2; //rounds
        }
        if(((Spells->use(no))->get_name()).compare(0,3,"(I)")==0){ //Special effect of Icespell
            monster.decrease_damage(200);
            return 1;
        }
        if(((Inventory->use(no))->get_name()).compare(0,3,"(L)")==0){ //Special effect of Lightningspell
            monster.decrease_escape_probability(50);
            return 3;
        }
    }else{
        cout<<"Spell is not available ."<<endl;
    }
}
int Hero::castSpell(Monster& monster){
    int rounds;
    if(Spells->Print_name()==-1)
        rounds=-1;
    else{
        cout<<endl<<"Choose the spell you want to use."<<endl;

        int number;
        if(spell_place==1) {
            do {
                cin >> number;
            } while (number != 1);
        }
        if(spell_place==2){
            do {
                cin >> number;
            } while (number != 1 && number != 2 );
        }
        if(spell_place==3){
            do {
                cin >> number;
            } while (number != 1 && number != 2 && number != 3);
        }
        rounds=useSpell(number-1,monster);
    }
    return rounds;
}
int Hero::attack(Monster& monster){
    cout<<"Attacking "<<monster.get_name()<<"."<<endl;
    if(equipped_two_hands_weapon!=-1)
        monster.decrease_defense((Inventory->use(equipped_two_hands_weapon)->get_damage())+strength);
    else if(equipped_left_weapon!=-1 && equipped_right_weapon!=-1)
        monster.decrease_defense((Inventory->use(equipped_left_weapon)->get_damage())+(Inventory->use(equipped_right_weapon)->get_damage())+strength);
    else if(equipped_left_weapon==-1 && equipped_right_weapon!=-1)
        monster.decrease_defense((Inventory->use(equipped_right_weapon)->get_damage())+strength);
    else if(equipped_left_weapon!=-1 && equipped_right_weapon==-1)
        monster.decrease_defense((Inventory->use(equipped_left_weapon)->get_damage())+strength);
    else if(equipped_left_weapon==-1 && equipped_right_weapon==-1 && equipped_two_hands_weapon==-1){
        cout<<"You have not equipped weapons!"<<endl;
        return -1;
    }
}

void Hero::decrease_life(int attack_rate){
    if(escaped_the_attack()){
        cout<<get_name()<<" has escaped the attack!"<<endl;
        return;
    }
    if(defense>=attack_rate) //First attack the defense of the hero and then his health power
        defense-=attack_rate;
    if(defense<attack_rate){
        int temp=defense;
        defense=0;
        if(equipped_armor!=-1) {
            cout << get_name() << "'s armor has broken!" << endl;
            Inventory->Delete_from_pos(equipped_armor);
            equipped_armor=-1; //The hero is no more equipped with an armor
        }
        attack_rate-=temp;
        this->health_from_damage(attack_rate);
    }
}





Warrior::Warrior(string n,int l=1,int hp=10000,int mp=10000,int s=300,int d=50,int a=270,int m=500,int exp=0,int alv=1000):Hero(n,l,hp,mp,s,d,a,m,exp,alv){
    cout<<get_name()<<" is a Warrior."<<endl;
}

void Warrior::levelUp(){
    Hero::levelUp(1);
}

Sorcerer::Sorcerer(string n,int l=1,int hp=10000,int mp=10000,int s=30,int d=300,int a=270,int m=500,int exp=0,int alv=1000):Hero(n,l,hp,mp,s,d,a,m,exp,alv){
    cout<<get_name()<<" is a Sorcerer"<<endl;
}
void Sorcerer::levelUp(){
    Hero::levelUp(2);
}

Paladin::Paladin(string n,int l=1,int hp=10000,int mp=10000,int s=270,int d=270,int a=40,int m=500,int exp=0,int alv=1000):Hero(n,l,hp,mp,s,d,a,m,exp,alv){
    cout<<get_name()<<" is a Paladin"<<endl;
}
void Paladin::levelUp(){
    Hero::levelUp(3);
}



Monster::Monster(string n,int l,int hp,int dmg, int d, int pb):Living(n,l,hp),attack_damage(dmg),defense(d),escape_probability(pb){
    cout<<"A Monster with attack damage "<<attack_damage<<" defense "<<defense<<" escape probability "<<escape_probability<<" was created."<<endl;
}
int Monster::get_attack_damage() const { return attack_damage;}
int Monster::get_escape_probability()const {return escape_probability;}
int Monster::get_defense()const{return defense;}

bool Monster::escaped_the_attack()const{
    return (rand() % 100) < get_escape_probability(); //The probability of escaping the attack is agility%. For example if agility==75 then the probability of escaping the attack is 75%.
};

void Monster::decrease_defense(int attack){
    if(escaped_the_attack()){
        cout<<get_name()<<" has escaped the attack!"<<endl;
    }else{
        if(defense>=attack)
            defense-=attack;
        else{
            int temp=defense;
            defense=0;
            attack-=temp;
            this->health_from_damage(attack);
        }
    }
}

int Monster::decrease_only_defense(int attack){ //returns the defense that the monster lost
    int temp=defense;
    if(defense>=attack) defense-=attack; else defense=0;
    return temp;
}

int Monster::decrease_damage(int attack){
    int temp=attack_damage;
    if(attack_damage>=attack) attack_damage-=attack; else attack_damage = 0;
    return temp;
}

int Monster::decrease_escape_probability(int attack){ //Reduce it as attack%
    int temp=escape_probability;
    if(escape_probability>0) escape_probability-=(attack/100)*escape_probability;
    return temp;
}

void Monster::resume_damage(int resume){ attack_damage+=resume; }
void Monster::resume_defense(int resume){defense+=resume;}
void Monster::resume_escape_probability(int resume){ escape_probability+=resume; }

void Monster::attack_hero(Hero& hero){
    hero.decrease_life(attack_damage);
}

Dragon::Dragon(string n,int l,int hp,int dmg, int d, int pb):Monster(n,l,hp,dmg,d,pb){
    cout<<"A dragon was created."<<endl;
}


Exoskeleton::Exoskeleton(string n,int l,int hp,int dmg, int d, int pb):Monster(n,l,hp,dmg,d,pb){
    cout<<"A Exoskeleton was created."<<endl;
}

Spirit::Spirit(string n,int l,int hp,int dmg, int d, int pb):Monster(n,l,hp,dmg,d,pb){
    cout<<"A Spirit was created."<<endl;
}






