// //#include <bits/stdc++.h>
#include<iostream>
#include<algorithm> 
#include<vector>
#include<map>

using namespace std;


void solve(){
    int n;
    cin >> n;

    vector<long long> a(n);
    vector<long long> v;
    map<long long, int> m;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    for (int i=0; i<n; i++) {
        m[(log2(a[i]) + 1)]++;
        v.push_back((log2(a[i]) + 1));
    }

    sort(v.begin(), v.end());
    long long ans = ((m[v[v.size() - 1]])+1)/2;
    
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}