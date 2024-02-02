#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	int t; 
    cin >> t; 
    
    while(t--){ 
        long long  m, n; 
        cin >> m >> n; 
        long long  arr[n]; 
        long long  s=0;
         
        for(int  i=0; i<n; i++){ 
            cin >> arr[i]; 
            s+=arr[i]; 
        } 
        
        cout << (((m*(m+1))/2)-s) << endl; 
    } 

	return 0;
}