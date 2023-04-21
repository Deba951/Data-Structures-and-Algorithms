#include <iostream>
using namespace std;

/*
void swap (int a, int b) {
    int temp = a; 
    a = b;
    b = temp;
}

int main(){
    int a = 2;
    int b = 4;

    swap(a, b);
    cout << a << ' ' << b << endl;

    return 0;
}
*/
//This code will not swap the values of a and b and the desired result not be achieved

/*
void swap (int *a, int *b) {   // Pointers
    int temp = *a; 
    *a = *b;
    *b = temp;
}


// This code gives us the desired result of but here we have declared two pointers
int main(){
    int a = 2;
    int b = 4;

    int* ap = &a; // declaration of pointer
    int* bp = &b; // declaration of pointer

    swap(ap, bp);
    cout << a << ' ' << b << endl;

    return 0;
}
*/



void swap (int *a, int *b) {   // Pointers
    int temp = *a; 
    *a = *b;
    *b = temp;
}

int main(){
    int a = 2
    int b = 4;

    swap(&a, &b);
    cout << a << ' ' << b << endl;

    return 0;
}