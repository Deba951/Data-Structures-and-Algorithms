//Custom Comparator Sort

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(pair<int, int> a, pair<int ,int> b){ // Creating or customizing a comperator 'comp'. Pair type created as required or used in program.
    return a.second < b.second; // Comperator as created in this case will sort according to the second element's order as mentioned --> 'a.second < b.second' irrespective of the first element.
}

bool compa(pair<int, int> a, pair<int ,int> b){ // Custom Comparator: irst elements in ascending order and if repetation is found in the elements, arrange the second element in descending order.
    if (a.first == b.first)
        return a.second > b.second;
}

bool comperator(pair<int, int> a, pair<int ,int> b){
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

int main(){

    int n; 
    cout << "Enter the number of elements:" << endl;
    cin >> n;
    cout << "Enter the elements:" << endl;
    vector <pair<int,int> > v;

    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

// Arranging the second elements in ascending order:
    sort (v.begin(), v.end(), comp); //Implementing custom Comperator 'comp' made in this program itself.
    for(int i = 0; i < n; i++)
        cout << v[i].first << " " << v[i].second << endl;

//Arranging the first elements in ascending order and if repetation is found in the elements, arrange the second element in descending order.
    sort (v.begin(), v.end(), compa); //Implementing custom Comperator 'compa' made in this program itself.
    for(int i = 0; i < n; i++)
        cout << v[i].first << " " << v[i].second << endl;

    return 0;
}