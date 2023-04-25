// Copyright srcmake.com 2018. C++ List example.
#include <iostream>
#include <list>
using namespace std;

int main()
    {
    cout << "Program began.\n";
    
    /* 
    Linked lists are good for O(1) insertions/removals at the beginning and end of the list. Inserting in the middle of the list isn't as good, as you have to traverse the list to find the item (as opposed to an array's constant time indexing). 
    */
    
    // Create a linked list of strings.
    list<string> srcList;
    
    // Insert some items in the list, sequentially.
    srcList.push_back("is ");
    srcList.push_back("really ");
    srcList.push_back("awesome.");
    
    // Insert an item to the front of the list.
    srcList.push_front("srcmake ");
    
    // Insert in the middle of the list.
    // Traverse the list using an iterator, and insert at our target position.
    list<string>::iterator it = srcList.begin();
    while(it != srcList.end())
        {
        string s = *it;
        if(s == "really ")
            {
            // Increment the iterator since we want to add the word after 'really'.
            it++;
            srcList.insert(it, "very ");
            it--;
            }
        it++;
        }
    
    // Print the list.
    for(auto s: srcList)
        {
        cout << s;
        }
    
    cout << "\nProgram ended.\n";
    return 0;
    }

/*
Output:
Program began.
srcmake is really very awesome.
​Program ended.
*/