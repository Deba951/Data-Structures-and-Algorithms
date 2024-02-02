#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m, k;
	    cin >> n >> m >> k;
	    
	    if(k>=m)
	        cout << "NO" << endl;
	   
	   // else{
    // 	    if ((k+k-1) <= m)
    // 	        cout << "YES" << endl;
	   //     else 
	   //         cout << "NO" << endl;
	   // }
	   
	   
        vector<int> v(n);
        for (int i=0; i<n; ++i) 
            cin >> v[i];
        

        sort(v.begin(), v.end());

        bool check = true;
        
        if ((v[n-1]+(k-1)) <= m )
            check = false;
        

        if (check) 
            cout << "No" << endl;
        
        else
            cout << "Yes" << endl;
	}
	
	return 0;
}