/* Map & Unordered Map:
    FEATURES:
    1. SORTED ACCORDING TO THE KEYS
    2. BST IN MAP AND HASHING IMPLEMENTAITON IN UNORDERED MAPS IN BACKEND
    3. STORE (KEY, VALUE) PAIR

    MAPS VS UNORDERED:
    BACKEND: BST VS HASHING
    SORTED VS UNSORTED
    NORMAL CASE: O(logN) VS O(1)
    WORST CASE: O(N) VS O(N)


    THREE WAYS OF INSERTING ELEMENTS IN A MAP OR AN UNORDERED MAP:
 1> m.insert({1,2});
 2> m.insert(pair<int,int>(1,2));
 3> m[1] = 2;
    WHERE 'm' IS THE MAP OR UNORDERED MAP.


    PRINTING THE ELEMENTS IN A MAP OR AN UNORDERED MAP:
    1) for (auto x:m)
        cout << x.first << x.second << endl;
    2) for (it = m.begin(); it != m.end(); ++it) {
        cout << '\t' << it->first
             << '\t' << it->second << '\n';
    }


    THE SNIPPETS MAY NOT COMPILE IN SOME EDITORS OR COMPILER AS IT DEPENDS UPON THE COMPILER OR EDITOR. 
*/


#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <unordered_map>

using namespace std;

int main(){

    map<int, int> m; // Map initialization
    m.insert(pair<int, int>(1, 2));   // Inserting Elements  Key -> 1, Value -> 2
    m[3] = 5;    // Inserting Elements  key -> 3, Value -> 5
    m[2] = 20;
    m[4] = 7;
    //for (auto x:m)
    //    cout << x.first << x.second << endl;

    map<int, int>::iterator it;     //Declaring the iterator
    cout << "The elements in the map are: " << endl;
    cout << "\tKEY\tELEMENT\n";

    // Printing the elements:
    for (it = m.begin(); it != m.end(); ++it) {
        cout << '\t' << it->first
             << '\t' << it->second << '\n';
    }

    //Assigning the elements of m to m1:
    map<int, int> m1(m.begin(), m.end());

    cout << "The elements in the new map after copying are: " << endl;
    cout << "\tKEY\tELEMENT\n";

    for (it = m.begin(); it != m.end(); ++it) {
        cout << '\t' << it->first
             << '\t' << it->second << '\n';
    }

    cout << "\n\n" << endl;

    unordered_map <int, int> um;  //Initializing Unordered Map
    um.insert(pair<int, int>(10,20));    // Inserting the elements
    um[3] = 50;   // Inserting Elements
    um[4] = 40;
    um[2] = 30;

    cout << "Unordered Map: \n" << endl;
    cout << "\tKEY\tELEMENT\n";

    unordered_map<int, int>::iterator iit;     //Declaring the iterator
    for (iit = um.begin(); iit != um.end(); ++iit) {
        cout << '\t' << iit->first
             << '\t' << iit->second << '\n';
    }

    cout << "\n\nIMPLEMENTAITON OF FIND OPERATOR :" << endl;
    // FIND OPERATION:
    cout << "\nFIRST USE OF FIND OPERATOR :" << endl;
    auto val = m.find(4);
    cout << val->first << " --> " << val->second << endl;

    cout << "\nSECOND USE OF FIND OPERATOR :" << endl;
    if (m.find(1)!=m.end()) 
        cout << "Present " << endl;
    else 
        cout << "False" << endl;
    if (m.find(5)!=m.end()) 
        cout << "Present " << endl;
    else 
        cout << "Not Present" << endl;

    cout << "\nANOTHER WAY OF USING THE FIND OPERATOR TO PRFORM THE SECOND TASK : \n" << endl;
    if (m[2]) 
        cout << "Present " << endl;
    else 
        cout << "Not Present" << endl;
    if (m[10]) 
        cout << "Present " << endl;
    else 
        cout << "Not Present" << endl;

    map <int, vector<int> > ma;  // Using vector in a map.
    return 0;  
}