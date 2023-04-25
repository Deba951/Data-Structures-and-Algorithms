/*
TOPIC:

1) binary search
2) lower bound()
3) upper bound()

LOWER BOUND  VS  UPPER BOUND
1) RETURNS ITERATOR IF ELEMENT FOUND  "VS"  RETURNS ITERATOR OF THE NEXT ELEMENT IF ELEMENT FOUND. 
2) RETURNS NEXT ITERATOR IF ELEMENT NOT FOUND  "VS"  RETURNS NEXT ITERATOR IF ELEMENT NOT FOUND.
*/


#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, key;
    cout << "Enter the  number of elements: " << endl;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    cout << "Enter the number to search: " << endl;
    cin >> key; // key => element to be searched


// LOWER BOUND: 

    auto itr = lower_bound(a, a+n, key);
    cout << itr << endl; // Prints the iterator of the element
    cout << *itr << endl; // * is added so as to get the value at that iterator.

    auto it = lower_bound(a, a+n, key) - a; //Get the index directly
    cout << it << endl; // index printing


// UPPER BOUND: 
    auto iitr = upper_bound(a, a+n, key);
    cout << iitr << endl; // Prints the iterator of the element
    cout << *iitr << endl; // * is added so as to get the value at that iterator.

    auto it = lower_bound(a, a+n, key) - a; //Get the index directly
    cout << it << endl; // index printing

    int ans = binary_search(a, a+n, key);
    cout << ans << endl;
    
    return 0;
}