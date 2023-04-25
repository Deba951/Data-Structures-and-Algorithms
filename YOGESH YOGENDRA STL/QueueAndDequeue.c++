/*
QUEUE  AND  DEQUE --->                       

    Queue functions:                 |                    Deque functions :  
    01. push()                       |                    01. push_fornt()   
    02. pop()                        |                    02. push_back()
    03. size()                       |                    03. pop_front()
    04. empty()                      |                    04. pop_back()  
    05. front()                      |                    05. front()  
    06. back()                       |                    06. back()

IT USES THE CONCEPT OF "FIFO", THAT IS FIRST IN FIRST OUT.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    queue <int> q;    // Initializing a queue

    q.push(10);    // push() function
    q.push(20);
    q.push(30);
    q.push(40);

    cout << q.size() << endl;    // size() function

    cout << q.front() << endl;   // front() function

    cout << q.back() << endl;    // back() function

    cout << q.empty() << endl;    // empty() function      IF OUTPUT IS 0 FOR THIS TYPE OF STSTEMENT IT INDICATES THAT THE QUEUE IS NOT EMPTY, THAT IS CONDITION TURNS TO BE FALE, AND HENCE THE INPUTTED STATEMENT CANNOT BE PERFORMED.

    while (!q.empty()) {     // Printing elements in the queue
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n" << endl; 



    deque <int> dq;    // Initializing a deque()

    dq.push_back(10);    // push_back() function
    dq.push_back(20);
    dq.push_back(30);
    dq.push_back(40);    // 10 20 30 40
    dq.push_front(50);    // push_front() function
    dq.push_front(60);
    dq.push_front(70);
    dq.push_front(80);    // 80 70 60 50 10 20 30 40 

    cout << dq.size() << endl;    // size() function

    while (!dq.empty()){     // Printing the deque
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << "\n" << endl;

    dq.push_back(100);    
    dq.push_back(200);
    dq.push_back(300);
    dq.push_back(400);    
    dq.push_front(500);    
    dq.push_front(600);
    dq.push_front(700);
    dq.push_front(800);    
    dq.pop_front();    // pop_front() function
    dq.pop_front();    // 600 500 100 200 300 400
    dq.pop_back();    // pop_back() function
    dq.pop_back();    // 600 500 100 200

    cout << dq.size() << endl;   

    while (!dq.empty()){    
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << "\n" << endl;

    return 0;
}