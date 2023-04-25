/*Reduce the given array:
arr = {10, 16, 7, 14, 5, 3, 12, 9}*/



#include <bits/stdc++.h>
#include <vector>
using namespace std;

    bool myCompare(pair<int, int>p1, pair<int, int> p2){
        return p1.first < p2.first;
    }

    int main()
    {
        int i;
        int arr[] = {10, 16, 7, 14, 5, 3, 12, 9};
        vector < pair<int, int> > v; 

        for (i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
        {
            v.push_back(make_pair(arr[i], i));
        }

        sort (v.begin(), v.end(), myCompare);
        for (i = 0; i < v.size(); i++)
            arr[v[i].second] = i;


        for (i = 0; i < v.size(); i++)
            cout << arr[i] << " ";

        return 0;
    }