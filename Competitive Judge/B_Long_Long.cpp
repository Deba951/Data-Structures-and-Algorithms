#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int t; 
    cin >> t;

    while(t--){

        long long int n; 
        cin >> n;
        long long sum=0, neg=0, min=0;
        for (int i=0; i<n; i++){
            
            long long int a;
            cin >> a;
            
            if (a<=0){
                if (a<0)
                    min=1;
            }

            else{
                if (min==1) 
                    neg++;
                min=0;
            }

            if (a<0)
                a *= -1;
            
            sum+=a;
        }

        if(min==1)
            neg++;

        cout << sum << " " << neg << endl;
    }

    return 0;
}