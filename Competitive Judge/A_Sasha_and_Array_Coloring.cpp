// #include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
 
signed main(){
 

 
    int t;
    cin>>t;
    while(t--){
    
        int n;
        cin >> n;
        
        long long a[n];
        for(int i=0; i<n; i++) 
            cin >> a[i];
        
        sort(a, a+n);
        int sum = 0;
        
        for(int i=0; i<n/2; i++){
            int sol = abs(a[i] - a[n-i-1]);
            sum = sum + sol;
        }
        
        cout << sum << endl;
    }
    return 0;
}