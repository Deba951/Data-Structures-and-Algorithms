/*
STACKS --->

Stack functions:--->
01. push()
02. pop()
03. top()
04. empty()
05. size()

IT USES THE CONCEPT OF "LIFO", THAT IS LAST IN FIRST OUT.
*/


//#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack <int> s;    // Initializing a Stack

    s.push(40);   // push() function
    s.push(50);   // push() function
    s.push(60);   // push() function
    s.push(70);   // push() function

    cout << s.top() << "\n" << endl;   // top() function

    s.pop();   // pop() function
    cout << s.top() << "\n" << endl;   

    cout << s.size() << "\n" << endl;   // size() function

    if (s.empty())      // empty() function
        cout << "Stack is empty!" << "\n" << endl;
    else
        cout << "Stack is not empty!" << "\n" << endl;

    // Printing stack elements
    while (!s.empty()){
        int value = s.top();
        cout << value << endl;
        s.pop();
    }
    
    return 0;
}