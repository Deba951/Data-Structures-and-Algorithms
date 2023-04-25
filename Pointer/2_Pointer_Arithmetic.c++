#include <bits/stdc++.h>
using namespace std;

int main() {

    int a = 10;
    int* ptr = &a;
    cout << ptr << endl;

    ptr++;
    cout << ptr << endl;

    return 0;
}

// A difference of 4 can be observed among the above two outputs.
// It is so because integers takes 4 bytes of sapce in the memory.
// If it would be char a difference of 1 would be noticed and so on.......

// We can acess and update variables using pointer.