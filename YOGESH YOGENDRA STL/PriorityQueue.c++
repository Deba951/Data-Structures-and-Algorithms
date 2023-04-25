/*
PRIRITY QUEUES --->

Priority queue functions:--->
01. push()
02. pop()
03. top()
04. empty()
05. size()

IT USES THE CONCEPT OF ORDER OF PRIORITY OF THE ELEMENTS. IT IS OF TWO TYPES; 1. MAXHIP (WHICH IS BASICALLY THE DECREASING ORDER),     AND,      2. MINHEAP (WHICH IS BASICALLY THE ASCENDING ORDER).
THE ELEMENTS AUTOMATICALLY GETS ARRANGED ACCORDING TO THE TYPE OF HEAP USE I.E, MAXHEAP OR MINHEAP.
*/


#include <bits/stdc++.h>
using namespace std;

int main(){

    priority_queue <int> pq;    // Initializing a priority queue of max_heap. Bydefault this type of initialization is considered as maxheap.

    pq.push(10);   // push() function
    pq.push(20);   
    pq.push(30);   
    pq.push(40);   // 40 30 20 10

    cout << pq.size() << endl;    // size() function

    while(!pq.empty()){     // empty() function and printing the priority queue.
        cout << pq.top() << " ";    // top() function
        pq.pop();    // pop() function
    }
    cout << endl;

    cout << pq.size() << endl;    // size() function

    cout << pq.empty() << endl << "\n"; // empty() function.    Boolean type output, i.e, if true it will print 1 and if false it will print false.
    //Here output will be 1 for this case as because all the elements has been popped out in thre while loop while printing.
    
    priority_queue <int, vector<int>, greater<int> > mpq;    // Initializing a priority queue of min_heap.

    mpq.push(50);   // push() function
    mpq.push(60);   
    mpq.push(70);   
    mpq.push(80);   // 50 60 70 80 

    cout << mpq.size() << endl;    // size() function

    while(!mpq.empty()){     // empty() function and printing the priority queue.
        cout << mpq.top() << " ";    // top() function
        mpq.pop();    // pop() function
    }
    cout << endl;

    cout << mpq.size() << endl;    // size() function

    cout << mpq.empty() << endl; // empty() function.    Boolean type output, i.e, if true it will print 1 and if false it will print false.
    //Here output will be 1 for this case as because all the elements has been popped out in thre while loop while printing.
    
    return 0;
}