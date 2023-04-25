/*
SET AND UNORDERED SET --->
------------------------------

List functions:--->
01. insert()
02. find()
03. erase()
04. count()

In a Set:
1. All the elements inside the set are in ordered manner not in a random order as in Unordered set.
2. All the elements in a set are unique, i.e, there will be no duplicates.

    SETS                                      |                     UNORDERED SET
   ------                                     |                    -----------------
                                          
1.  Sorted                                    |     1. Random
2.  Backend: Binary Search Tree (BST)         |     2. Backend: Hashing
3.  Avarage Case:  oreder of (logN),  O(logN) |     3. Avarage Case:  oreder of 1,  O(1)
4.  Worst Case: oreder of N,  O(N)            |     4. Worst Case: oreder of N,  O(N)
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    set <int> s;    // Initializing a normal Set

    s.insert(50);    // insert() function
    s.insert(10);    // 10 50
    s.insert(20);    // 10 20 50
    s.insert(40);    // 10 20 40 50
    s.insert(30);    // 10 20 30 40 50 
    s.insert(50);    // 10 20 30 40 50 
    s.insert(30);    // 10 20 30 40 50 
    s.insert(60);    // 10 20 30 40 50 60

    cout << s.size() << endl;     // size() function

    auto y = s.find(30);    // find() function.    auto data type has been declared because find() function returns the iterator i.e, the loction not the index. Hence we dont use int, lomg, double, etc.
    cout << *(y) << endl;  

    if (s.count(20))    // count() function
        cout << "Present" << endl;    
    else
        cout << "Absent" << endl;

    if (s.count(90))    // count() function
        cout << "Present" << endl;    
    else
        cout << "Absent" << endl;
   
    // count actually returns the number of times an element is present in the set. But we know that in a set there is always an unique element. Hence count() will always return 0 or 1 in case of sets, i.e, 0 in case the element is not found and 1 in case the element is present.
    // In case of sets the count() function is used to check if an element is present in the set or not without using the find() function which returns the location or the iterator of the element.

    for (auto x:s){               // Printing the set
        cout << x << " "; 
    }
    cout << endl;

    s.erase(60);      // erase() function        Searching occured in order of log(n).
    s.erase(y);       // Searching occured in order of 1 because we directly given the iterator to find.

    for (auto x:s){               
        cout << x << " "; 
    }
    cout << endl;




    unordered_set <int> us;    // Initializing an Unordered Set

    us.insert(50);    // insert() function
    us.insert(10);    // 10 50
    us.insert(20);    // 10 20 50
    us.insert(40);    // 10 20 40 50
    us.insert(30);    // 10 20 30 40 50 
    us.insert(50);    // 10 20 30 40 50 
    us.insert(30);    // 10 20 30 40 50 
    us.insert(60);    // 10 20 30 40 50 60

    cout << us.size() << endl;     // size() function

    //auto y = us.find(30);    // find() function. It will be shown as an error statemente because unordered_set uses hashing and not BST hece the iterator is meaningless here.
    //cout << *(y) << endl;  

    if (us.count(20))    // count() function
        cout << "Present" << endl;    
    else
        cout << "Absent" << endl;

    if (us.count(90))    // count() function
        cout << "Present" << endl;    
    else
        cout << "Absent" << endl;

    for (auto x:us){               // Printing the set
        cout << x << " "; 
    }
    cout << endl;

    us.erase(60);      // erase() function        Searching occured in order of log(n).
    //us.erase(y);       // This statement will give error because in unorderd set BST is not applicable hence iterator will not work. It uses Hashing.

    for (auto x:us){               
        cout << x << " "; 
    }
    cout << endl;

    return 0;
}