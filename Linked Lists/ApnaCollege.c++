/*
Single block of memories with partitions.  --> Array
Multiple blocks of memory linked to each other. --> Linked List

Limitations of Array-:
> Fixed size.
> Contiguous block of memory.
> Inserting or deleting is costly.

Properties of linked lists-:
> Size can be modified.
> Non contiguous.
> Inserting or deletion at any point is easy.

NODE -> Block of memory
Head pointer stores the adress of the first NODE.
Last pointers NODE contains NULL pointer implies last element.
*/

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

// Given a linked list having elements 1 and 2. We need to add an element 3 at the end of the list.

void insertEnd(node* &head, int val){

    node* n = new node(val);
    node* temp =  head;
    
    if (head == NULL){    // if linked list is empty
        head = n;
        return;
    }

    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = n;
}

// Given a linked list having elements 1 and 2. We need to add an element 4 at the begining of the list.

void insertBeg(node* &head, int val){

    node* n = new node(val);
    n->next = head;
    head = n;
}

void display(node* head){

    node * temp = head;
    while (temp!=NULL){
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

//Searching

bool search(node* head, int key){

    node * temp = head;
    while (temp!=NULL){
        
        if (temp->data == key)
            return true;
        temp = temp->next;
    }
    return false;
}

int main(){

    node* head = NULL;
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    display(head);
    insertBeg(head, 4);
    display(head);
    cout << search(head, 5) << endl; //Not present, output 0.
    cout << search(head, 3) << endl; //Present, output 1.
    return 0;
}