// int positionOfTheCharacterInTheArray = 'character' - 'a'

/*
    String -------------> abcdabehf
    Number of queries --> 5
    Queries ------------> a
                          g
                          h
                          b
                          c
*/

//#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
    
int main() {
    
    string s;
    cin >> s;

    //precompute
    int hash[256]={0};      // Max characters are 256
    for(int i=0; i<s.length(); i++)
        hash[s[i]]++;

    int q;
    cin >> q;

    while(q--){
        char c;
        cin >> c;

        //fetch
        cout << hash[c] << endl;
    }
return 0;
}

// Array is enough for hashing in case of characters.