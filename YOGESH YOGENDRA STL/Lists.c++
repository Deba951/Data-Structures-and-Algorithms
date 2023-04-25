/*
LISTS OR LINKED LISTS --->
-----------

List functions:--->
01. push_fornt()
02. push_back()
03. pop_front()
04. pop_back()
05. front()
06. back()
07. reverse()
08. sort()
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    list <int> l;    // Initializing a List
     
    l.push_back(10);    // push_back() functions       10
    l.push_back(20);    // 10, 20
    l.push_front(30);   // push_front() functions      30, 10, 20

    list <int> :: iterator it;     // ITERATING THROUGH THE LIST, it IS THE NAME OF THE ITERATOR AND :: IS THE SCOOP

    for(it = l.begin(); it != l.end(); it++)    // begin() function.  
    //END denotes the position after the last element in the list.
        cout << *it << " " << endl;
    cout << endl;

    cout << l.front() << endl;    // front() function
    cout << l.back() << endl;     // back() function
    
    l.reverse();      // reverse() function
    for(it = l.begin(); it != l.end(); it++)  
        cout << *it << " " << endl;
    cout << endl;

    l.sort();   // sort() function
    for(it = l.begin(); it != l.end(); it++) 
        cout << *it << " " << endl;
    cout << endl;

    l.pop_back();      // pop_back() function
    for(it = l.begin(); it != l.end(); it++) 
        cout << *it << " " << endl;
    cout << endl;

    l.pop_front();      // pop_front() function
    for(it = l.begin(); it != l.end(); it++) 
        cout << *it << " " << endl;
    cout << endl;

    return 0;
}