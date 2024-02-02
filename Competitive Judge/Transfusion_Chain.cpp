#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string arr[n];
        for(int i=0; i<n; i++)
            cin >> arr[i];
        
        int a=0, b=0, ab=0, o=0, ans=0;

        for(int i=0; i<n; i++){
            if(arr[i]=="A")
                a++;
            else if(arr[i]=="B")
                b++;
            else if(arr[i]=="AB")
                ab++;
            else if(arr[i]=="O")
                o++;
        }

        ans += ab;
        ans+=o;
        ans+=max(a, b);

        cout << ans << endl;
    }
    return 0;
}