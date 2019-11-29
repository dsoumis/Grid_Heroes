#ifndef RPG_LISTS_H
#define RPG_LISTS_H
#include "Items.h"
#include "Spells.h"
// List class
class Item;
class Item_List{
    struct Node {
        Item* data;
        Node* next;
        Node(Item*,Node*);
        Item* Data() { return data; };
        Node* Next() { return next; };
    };
    Node *head;
public:
    Item_List():head(NULL){};
    int Print_name()const;
    void insert_last(Item*);
    void Delete_from_pos(int);
    Item* use(int); //Returns the item of this specific place in the list
};

class Spell;
class Spell_List{
    struct Node {
        Spell* data;
        Node* next;
        Node(Spell*,Node*);
        Spell* Data() { return data; };
        Node* Next() { return next; };
    };
    Node *head;
public:
    Spell_List():head(NULL){};
    int Print_name()const;
    void insert_last(Spell*);
    void Delete_from_pos(int);
    Spell* use(int); //Returns the spell of this specific place in the list
};
#endif //RPG_LISTS_H
