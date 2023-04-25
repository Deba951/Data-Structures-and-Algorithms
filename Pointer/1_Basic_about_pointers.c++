#include <bits/stdc++.h>
using namespace std;

int main() {

    //What is a pointer ---> Data type which holds the adress of other data types

    int a=3;
    int* b = &a;

    // Data type of the pointer will be according to the data type of the variable we are dealing with.
    // As for example, here we declared a as integer, so we initialized the pointer as an inter too.
    // If a would been initialised as a char then the pointer would also be initialized as char, and so on.......   
    // & ---> Adress of operator; operartor is a
    cout << "The adress of a is: " << &a << endl;
    cout << "The adress of a is: " << b << endl;

    // * ---> Dereference operator; operartor is a
    cout << "The value at adress b is: " << *b << endl;

    //pointer to pointer
    int** c = &b;
    cout << "The adress of b is: " << &b << endl;
    cout << "The adress of b is: " << c << endl;
    cout << "The value at adress c is: " << *c << endl;
    cout << "The value at adress value_at(value_at(c)) is: " << **c << endl;

    return 0;
}