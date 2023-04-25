/*
TOPICS-:

1) *max_elements()
2) next_permutation()
3) __builtin_popcount()
4) BinarySearch()
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    /* FINDING LARGEST ELEMENT IN AN ARRAY:- SIMPLE PROCEDURE.
    int n;
    cout << "Enter the number of elements: " << endl;
    cin >> n;
    int a[n];
    cout << "Enter the elements: " << endl;
    for(int i=0; i<n; i++) cin >> a[i];
    int ma = 0;
    for(int i=0; i<n; i++){
        if (a[i] > ma) 
            ma = a[i];
    }*/
    cout << "Finding the largest element in an array using the STL method: " << endl;
    int n=4;
    int a[4] = {56, 87, 23, 45};
    int ma = 0;
    ma = *max_element(a, a+n);  //function to find the largest element. Syntax-> *max_element(strting position(here it is 'a'), end position(here it is 'a+n'))
    cout << "Largest element is: " <<ma << endl;

    
    

    //  FINDING THE PERMUTATION OF THE ENTERED ELEMENTS: SIMPLE WAY IS TO USE RECURSSION.
    cout << "\n\nFinding the permutation using STL method: " << endl;
    string s = "ABC";
    do{
        cout << s << endl;
    }while(next_permutation(s.begin(), s.end()));
    // It returns the exact next permutation of the present condition.
    cout << "Property of this function demonstration: " << endl;
    string st = "BCA";
    do{
        cout << st << endl;
    }while(next_permutation(st.begin(), st.end()));




    //  FINDING THE NUMBER OF 1s PRESENT IN A BINARY SET KNOWN AS 'SETBASE'. SIMPLIEST WAY:- IS TO RUN A WHILE LOOP AND WHENEVER A '1' IS ENCOUNTERED INCREASE THE POINTER BY 1 AND IF ZERO IS ENCOUNTERED KEEP THE POINTER UNINCREASED.
    //int j; cin >> j;
    cout << "\n\nFINDING THE NUMBER OF SETBASE OF A NUMBER: " << endl;
    int j = 10; // 1010 in binary
    int ans = __builtin_popcount(j); // First it converts the inputted number in Binary and then counts number of 1s in it.
    cout << ans << endl;




    // BINARY SEARCH USING THE STL METHOD PRESENT. SIMPLIEST WAY:- PERFORM BINARY SEARCH OPRATION BY DIVIDIN THE ARRAY IN SORED ODER INTO TWO PARTS AND SO ON.
    cout << "Searching elements in an array using binary_search() method: " << endl;
    cout << "Enter the number of elements: " << endl;
    int g; cin >> g; int arr[g];
    cout << "Enter the elements: " << endl;
    for(int i=0; i<g; i++) cin >> arr[i];
    sort (arr, arr+g);
    cout << "Enter the number to be searched" << endl;
    int key; cin >> key;
    if (binary_search(arr, arr+g, key)) // Syntax --> binary_search(starting point(here 'arr'), ending point(here 'arr+g', element to be searched(here 'key')))
        cout << "Present" << endl;
    else cout << "Not Found" << endl;

    return 0;
}