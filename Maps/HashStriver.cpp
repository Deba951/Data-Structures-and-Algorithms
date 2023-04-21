/*
    size of array ------------------------> 5
    Array elements -----------------------> 1 3 2 1 3
    Numbers of elements to be searched ---> 5
    Elements to be searched -------------->
                                            1
                                            4
                                            2
                                            3
                                            12
*/
 
 
//#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int hash[10000000];

int main() {

    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];


    // precompute
    int hash[13]={0};   //any calculated or preknown number is the size
    for(int i=0; i<n; i++)
        hash[arr[i]]++;

    int q;
    cin >> q;

    while(q--){
        int number;
        cin >> number;


        //fetch
        cout << hash[number] << endl;
    }
return 0;
}

// If we use array we can take 10^6 inside the main method and 10^7 glibally.