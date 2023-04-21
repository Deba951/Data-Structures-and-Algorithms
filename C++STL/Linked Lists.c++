// Copyright srcmake.com 2018.
// C++ Linked List (Singly and Doubly) Examples
// Official webpage for this tutorial: https://www.srcmake.com/home/linkedlist

/* Compile with:
g++ -std=c++14 main.cpp -o run
./run
*/

#include <iostream>
using namespace std;

  
////// LINKED LIST NODES //////
// A singly node.
struct singlyNode
    {
    int data;
    singlyNode* next;
    };
    
// A doubly node.
struct doublyNode
    {
    int data;            // The data we're storing.
    doublyNode* next;    // The next     node in the list.
    doublyNode* prev;    // The previous node in the list.
    };
    

////// ADD NODE TO LIST //////
// Add a node to the end of a doubly linked list. 
// Pass a reference to a pointer to the root node, and the data.
void AddNode(doublyNode*& root, int data)
    {
    // Special case: if the root is null, then since this is the first node, make root point to it.
    if(root == NULL)
        {
        //cout << "root";
        // Create a new node, and set it's next and prev pointers to null, and set the data.
        doublyNode* nodePtr = new doublyNode();
        nodePtr->next = NULL;
        nodePtr->prev = NULL;
        nodePtr->data = data;
        
        // Now make the root pointer that we were passed point to the address of this new node.
        root = nodePtr;
        }
    // Normal case: Go to the end of the list, create a new node for the data, and add it to the end of the list.
    else
        {
        // Create a new node for the data we're trying to add.
        doublyNode* newnode = new doublyNode();
        newnode->next = NULL;
        newnode->data = data;
        
        // Find the node at the end of the list.
        // Create a pointer that starts out pointing to the root node.
        doublyNode* nodePtr = root;
        // Keep going down the list until we find the last node.
        while(nodePtr->next != NULL)
            {
            // Set the node to the next one in the list.
            nodePtr = nodePtr->next;
            }
        
        // node is now pointing to the node at the end of the last.
        // Make the newnode's prev pointer point to the address of the last node.
        newnode->prev = nodePtr;
        // Make the last node's next address point to the address of the new node.
        nodePtr->next = newnode;
        }
    }
     
     
////// PRINT NODES //////
// Print all nodes in the list. Recursively print the node's data and move to the next node.
void PrintLinkedList(doublyNode* nodePtr)
    {
    // If this node is null, stop.
    if(nodePtr == NULL) 
        { 
        cout << endl; 
        return; 
        }
    
    // Print this node's data.
    cout << nodePtr->data << " ";
    
    // Recursively check the next node in the list.
    PrintLinkedList(nodePtr->next);
    }

////// MAIN //////
int main() 
    {
    cout << "Program started.\n";
    
    // Our linked list will be 4 6 1 -5.
    // Create a pointer for the root of our linked list. Set it to point to nothing.
    doublyNode* root = NULL;
    // Add the nodes we want to our linked list.
    AddNode(root, 4);
    AddNode(root, 6);    
    AddNode(root, 1);
    AddNode(root, -5);
    
    // Print the list (by traversing it in order). Pass it the root pointer.
    cout << "\nPrinting Linked List: ";
    PrintLinkedList(root);
    
    cout << "Program ended.\n";
    return 0;
    }