#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin >> t;
	
	while(t--){
	    int n, x, k, p, ans;
	    cin >> n >> x >> k >> p;
	    
	    if(k==0)
	        cout << p << endl;
        
        else if(k<=x){
            ans=p+(k*10);
            
            if(k==n)
    	        ans+=20;
    	        
	        cout << ans << endl;
        }
        
        else{
    	    ans=p+(10*x)+((k-x)*5);
    	    
    	    if(k==n)
    	        ans+=20;
    	        
            cout << ans << endl;
        }
	}
	
	return 0;
}