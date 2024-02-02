//#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
    
int main() {
    int t;
    cin >> t;
    while (t--){
        
        int n, m, h;
        cin >> n >> m >> h;

        long long energy[n];
        for(int i=0; i<n; i++)
            cin >> energy[i];

        sort(energy, energy+n, greater<int>());

        long long power[m];
        for(int i=0; i<m; i++){
            cin >> power[i];
            power[i] *= h;
        }

        sort(power, power+m, greater<int>());
        long long ans=0;

        for(int i=0; i<min(m, n); i++){
            long long k=power[i];
            
            if(k<=energy[i])
                ans+=k;
            else
                ans+=energy[i];
        }

        cout << ans << endl;
    }
return 0;
}