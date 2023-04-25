/*
PAIRS --->

pair <data type, data type> 'pair name let' p;
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    
    pair <int, int> p;    // Initialising the pair

    p.first = 100;    // Taking input the first data in the pair 
    p.second = 200;    // Taking input the second data in the pair 
    
    cout << "{" << p.first << ", " << p.second << "}" << endl;    // Printing the pair in the inputted format
    
    pair <int, pair<int, int> > pt;

    pt.first = 1000;
    pt.second.first = 2000;
    pt.second.second = 3000;

    cout << "{" << pt.first << ", " << "{" << pt.second.first << ", " << pt.second.second << "} " << "}" << endl; 
    

    // GRAPH TYPE:
    
    int n ;
    cout << "Enter the number of elements: " << endl;
    cin >> n;
    vector<pair<int, int> > v;
    
    cout << "Enter the elements one by one: " << endl;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
        // alternately we can input pair in vector in short is:--->   v.push_back({x,y});
    }

    for (int i = 0; i < n; i++) {
        cout << v[i].first << " " << v[i].second << endl;
    }

    return 0;
}