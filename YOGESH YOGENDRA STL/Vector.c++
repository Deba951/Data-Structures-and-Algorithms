/*
VECTORS --->
-----------

Vector functions:--->
01. push_back()
02. pop_back()
03. size()
04. resize()
05. end()
06. begin()
07. clear()
08. empty()
09. erase()
10. insert()
11. reverse()
12. sort()
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    vector <int> v;    // Initializing a Vector

    v.push_back(4);   // push_back functions
    v.push_back(5);   // push_back functions
    v.push_back(6);   // push_back functions
    v.push_back(7);   // push_back functions

    cout << v.size() << "\n" << endl;   // size() functions

    for (int i = 0; i < v.size(); i++)   // Printing elements in the vector
        cout << v[i] << "  ";

    v.pop_back(); // pop_back functions
    v.pop_back(); // pop_back functions

    cout << "\n \n" << v.size() << "\n" << endl; // size() functions
    
    for (int i = 0; i < v.size(); i++)  // Printing elements in the vector
        cout << v[i] << "  ";
    cout << endl << "\n";

    v.resize(6);  // Resize( function
    for (int i = 0; i < v.size(); i++)  // Printing elements in the vector
        cout << v[i] << "  ";
    cout << endl << "\n";
    
    // POINTERS IN TERMS OF STL IS ---> ITERATORS.
    
    cout << *(v.begin()) << "\n" << endl;  // Pointing to print the first elment in the vector using an iterator "*" and begin() function.

    cout << *(v.end()-1) << "\n" << endl;  // Pointing to print the last elment in the vector using an iterator "*" and end() function.

    v.clear();  // Delete all the elements present in the vector ---> clear() function.
    
    cout << v.size() << "\n" << endl;

    if (v.empty())    // empty() function
        cout << "Empty vector" << "\n" << endl;
    else
        cout << "Vector Is Not Empty " << "\n" << endl;

    v.push_back(4);
    v.push_back(5); 
    v.push_back(6); 
    v.push_back(7); 
    
    v.erase(v.begin()+1);  // erase() function
    for (int i = 0; i < v.size(); i++)  // Printing elements in the vector
        cout << v[i] << "  ";
    cout << endl << "\n";

    v.insert(v.begin()+1, 8);   // insert() function ---->  (VECTOR NAME).INSERT (POSITION, VALUE)
    for (int i = 0; i < v.size(); i++)  // Printing elements in the vector
        cout << v[i] << "  ";
    cout << endl << "\n";

    sort(v.begin(), v.end());   // sort() function ---> SORT(VECTOR.BEGIN(), VECTOR.END())
    for (int i = 0; i < v.size(); i++)  // Printing elements in the vector
        cout << v[i] << "  ";
    cout << endl << "\n";

    reverse(v.begin(), v.end());  // resize() function ---> REVERSE(VECTOR.BEGIN(), VECTOR.END())
    for (int i = 0; i < v.size(); i++)  // Printing elements in the vector
        cout << v[i] << "  ";
    cout << endl << "\n";

    return 0;
}