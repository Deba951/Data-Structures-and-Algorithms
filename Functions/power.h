/*
User-defined header files: - Instead of writing a large and complex code, we can create your own header files and include them in our program to use it whenever we want. It enhances code functionality and readability. Below are the steps to create our own header file:

Step 1:  Write your own C/C++ code and save that file with “.h” extension. Below is the illustration of the header file:

Step 2:  Create a “File_name.cpp”   file.  Include your header file with “#include” in your C/C++ program as shown below: 
*/

//Code For Header File :   
//  save this file with     "" power.h ""  name


int powerOf(int a, int b)
{
    int ans = 1;
    for (int i = 1; i <= b; i++)
    {
        ans = ans * a;
    }
    return (ans);
}
//Code of Main file :
#include <iostream> 

// include your created header file here

#include "power.h"  //name is same as header file name

/*  It searches in the directory containing the current file. */

using namespace std;

// Driver Code
int main()
{
     int x = powerOf(2, 5) + 3 ;
     cout<<x;
    return 0;
}