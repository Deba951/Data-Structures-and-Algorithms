#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {10,20,30,40};
    cout << *arr << endl;

    int* ptr = arr;
    for (int i = 0; i < 4; i++) {
        cout << *ptr << endl;
        /* cout << *arr << endl;
        arr ++ */  //Illegal

        // To do this without using pointer
        cout << *(arr+i) << endl;
        ptr++;
    }
 
    return 0;
}

// We can acess and update variables using pointer.