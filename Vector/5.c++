#include<iostream>
#include<vector>
using namespace std;
void display(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main()
{ 
    vector <int> vec1;
    int element, size;
    cout<<"Enter the size of your vector"<<endl;
    cin>>size;

    for (int i = 0; i < size; i++)
    {
        cout<<"Enter an element to add to this vector: ";
        cin>>element;
        vec1.push_back(element);
    }

    display(vec1);    
    display(vec1);
    vec1.pop_back();
    display(vec1);

    vector <int>::iterator it;
    for (it = vec1.begin(); it != vec1.end(); it++)
            cout << *it << endl;
            vec1.insert(it,566);
        display(vec1);

   
    /*vector<int> :: iterator iter = vec1.begin();
    display(vec1);
    vector<int> :: iterator iter = vec1.begin();
    vec1.insert(iter,566);
    display(vec1);*/

    
    vector <int> vec5;      //zero length integer vector
    vector <char> vec6(4);  //4-element character vector
    vector <char> vec7(vec6);//4-element character vector from vec2
    vector <int> vec8(6,3); //6-element vector of 3s
    
    return 0;
}