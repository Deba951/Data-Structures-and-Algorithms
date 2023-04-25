#include<iostream>
using namespace std;

int main(){
    int n, c=0;
    cin >> n;
    
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int min=arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]<min)
            min=arr[i];
    }

    for(int i=0; i<n; i++){
        if(arr[i]==min){
            cout << "Present at index " << i << endl;
            c++;
            break;
        }
    }
    if(c<1)
        cout << "Not Present" << endl;
}