/*
    size of array ------------------------> 7
    Array elements -----------------------> 1 2 3 1 3 2 12
    Numbers of elements to be searched ---> 5
    Elements to be searched --------------> 1
                                            2
                                            3
                                            4
                                            12
*/



//#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
    
int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    //precompute
    map<int, int> m;
    for(int i=0; i<n; i++)
        m[arr[i]]++;

    //Iterate in map
    for(auto it:m)
        cout << it.first << " -> " << it.second << endl;

    int q;
    cin >> q;

    while (q--){
        int number;
        cin >> number;

        //fetching
        cout << m[number] << endl;
    }
    
return 0;
}

// Time complexity of map --> O(log n) for all cases.

// Time complexity of unordered map is O(1) for best and average case. For worst case it takes O(n).