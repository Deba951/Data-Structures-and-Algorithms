#include<iostream>
#include<algorithm>
using namespace std;
    
int main() {
    int t, c=0;
    cin >> t;
    while(t--) {

        int n, m, total=0;
        cin >> n >> m;
        int candy[n];
        for(int i = 0; i < n; i++)
            cin >> candy[i];

        for(int i = 0; i < n; i++)
            total = total + candy[i];

        int left = total%m;
        c=c+1;
        cout << "Case #" << c << ": " << left << endl;
    }
return 0;
}