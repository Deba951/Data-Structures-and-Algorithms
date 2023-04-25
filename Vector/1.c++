#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    //Initiating Vector
    vector <int> v;

    //Inserting the values
    for (int i = 1; i <= 5; i++)
        v.push_back(i);

    //Printing the Vector
    cout << "The elements in the vector is:\n" << endl;
    for (int i = 0; i <= 4; i++)
        cout << v[i] << endl;

    //Size, Capacity and Maximum size of the vector
    cout << "Size:" << v.size() << endl;
    cout << "Capacity:" << v.capacity() << endl;
    cout << "Maximun Size:" << v.max_size() << endl;

    //Check if the vector is empty or not empty
    if (v.empty()) 
        cout << "Vector is empty \n"<< endl;
    else
        cout << "Vector is not empty \n"<< endl;

    //Print First, Lastr and i'th element
    cout << "First:" << " " << v.front() << endl;
    cout << "Last:" << " " << v.back() << endl;
    cout << "Random such as third:" << "  " << v.at(3) << endl; // Here as an example we used 3'rd position but any position can be used

return 0;
}
