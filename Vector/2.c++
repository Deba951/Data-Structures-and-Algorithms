#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{
    vector <int> v;
    v.push_back(1); //Inserting values in a vector
    v.push_back(2);
    v.push_back(3);

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
        //Output 1, 2, 3
    
    vector <int>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
        cout << *it << endl;
    //Output 1, 2, 3

    for (auto element : v) //Automatically chooses or identifies the data type of the elements in the vector
        cout << element << endl; //Output 1, 2, 3
    
    v.pop_back(); // Output 1, 2

    vector <int> v2(3, 50);
    // 50, 50, 50 elements in the vector if initialised as above

    // Swapping elements among two vectors
    swap (v, v2); 
    for (auto element : v) 
        cout << element << endl;
    for (auto element : v) 
        cout << element << endl;
    
    sort (v.begin(), v.end());
        for (auto element : v) 
            cout << element << endl;

    return 0;
}