// #include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    
    while(t--){
    
        long long n;
        cin >> n;
        long long sum=0;
        
        while(n){
            sum=sum+n;
            n=n/2;
        }

        cout << sum << endl;
    }
    return 0;
}