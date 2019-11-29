#include "Lists.h"
Item_List::Node::Node(Item* aData, Node *aNext):data(aData),next(aNext) {}
void Item_List::Delete_from_pos(int pos) {
    // Create a temp pointer
    Node *tmp = head;

    // No nodes
    if ( tmp == NULL )
        return;

    // Last node of the list
    if ( tmp->Next() == NULL ) {
        delete tmp;
        head = NULL;
    }
    else {
        if(pos!=0){
            // Parse through the nodes
            Node *prev;
            for (int i = 0; i < pos; i++) {
                prev = tmp;
                tmp = tmp->Next();
            }

            // Adjust the pointers
            prev->next=tmp->Next();
            // Delete the current node
            delete tmp;
        }else{
            head=head->Next();
            delete tmp;
        }
    }
}
Item* Item_List::use(int pos) {
    // Temp pointer
    Node *tmp = head;
    // Parse the list
    for (int i = 0; i <pos; i++) {
        tmp = tmp->Next();
    }
    return tmp->Data();
}
void Item_List::insert_last(Item* data) {
    // Create a new node
    Node* newNode = new Node(data,NULL);
    // Create a temp pointer
    Node *tmp = head;

    if ( tmp != NULL ) {
        // Nodes already present in the list
        // Parse to end of list
        while ( tmp->Next() != NULL ) {
            tmp = tmp->Next();
        }

        // Point the last node to the new node
        tmp->next=newNode;
    }
    else {
        // First node in the list
        head = newNode;
    }
}
int Item_List::Print_name()const{
    // Temp pointer
    Node *tmp = head;

    // No nodes
    if ( tmp == NULL ) {
        cout << "No items." << endl;
        return -1;
    }

    // One node in the list
    if ( tmp->Next() == NULL ) {
        cout<<"1.";
        cout << (tmp->Data())->get_name()<<endl;
    }
    else {
        // Parse and print the list
        int number=1;
        do {
            cout<<number<<".";
            cout << (tmp->Data())->get_name()<<endl;
            tmp = tmp->Next();
            number++;
        }
        while ( tmp != NULL );

    }
}

Spell_List::Node::Node(Spell* aData, Node *aNext):data(aData),next(aNext) {}
void Spell_List::Delete_from_pos(int pos) {
    // Create a temp pointer
    Node *tmp = head;

    // No nodes
    if ( tmp == NULL )
        return;

    // Last node of the list
    if ( tmp->Next() == NULL ) {
        delete tmp;
        head = NULL;
    }
    else {
        if(pos!=0){
            // Parse through the nodes
            Node *prev;
            for (int i = 0; i < pos; i++) {
                prev = tmp;
                tmp = tmp->Next();
            }

            // Adjust the pointers
            prev->next=tmp->Next();
            // Delete the current node
            delete tmp;
        }else{
            head=head->Next();
            delete tmp;
        }
    }
}
void Spell_List::insert_last(Spell* data) {
    // Create a new node
    Node* newNode = new Node(data,NULL);
    // Create a temp pointer
    Node *tmp = head;

    if ( tmp != NULL ) {
        // Nodes already present in the list
        // Parse to end of list
        while ( tmp->Next() != NULL ) {
            tmp = tmp->Next();
        }

        // Point the last node to the new node
        tmp->next=newNode;
    }
    else {
        // First node in the list
        head = newNode;
    }
}
int Spell_List::Print_name()const{
    // Temp pointer
    Node *tmp = head;

    // No nodes
    if ( tmp == NULL ) {
        cout << "You have not acquired spells for this hero." << endl;
        return -1;
    }

    // One node in the list
    if ( tmp->Next() == NULL ) {
        cout<<"1.";
        cout << (tmp->Data())->get_name()<<endl;
    }
    else {
        // Parse and print the list
        int number=1;
        do {
            cout<<number<<".";
            cout << (tmp->Data())->get_name()<<endl;
            tmp = tmp->Next();
            number++;
        }
        while ( tmp != NULL );
    }
}
Spell* Spell_List::use(int pos) {
    // Temp pointer
    Node *tmp = head;
    // Parse the list
    for (int i = 0; i <pos; i++) {
        tmp = tmp->Next();
    }
    return tmp->Data();
}