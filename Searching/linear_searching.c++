/*
<<<<<<<<********-------------------------------- LINEAR SEARCH --------------------------------********>>>>>>>>

A simple approach is to do a linear search, i.e  

Start from the leftmost element of arr[] and one by one compare x with each element of arr[]
If x matches with an element, return the index.
If x doesn’t match with any of elements, return -1




Problem 1: Given an array arr[] of n elements, write a function to search a given element x in arr[].

Examples :  

Input : arr[] = {10, 20, 80, 30, 60, 50, 110, 100, 130, 170}
          x = 110;

Output : 6
Element x is present at index 6

Input : arr[] = {10, 20, 80, 30, 60, 50, 110, 100, 130, 170}
           x = 175;

Output :  -1
Element x is not present in arr[].
*/

// SOLUTION:

#include <iostream>
using namespace std;

int search(int n, int arr[], int x){

    int i;
    for (i = 0; i < n; i++){
        if (arr[i] == x)
            return i;            
    }

    return -1;
}

int main(){

    int n, i;
    cout << "Enter the number of elements in the array" << endl;
    cin >> n;

    int arr[n];
    cout << "Enter the elements in array" << endl;
    for (i = 0; i < n; i++) 
        cin >> arr[i];

    int x;
    cout << "Enter The number to be searched" << endl;
    cin >> x;

    int ans = search(n, arr, x);

    if (ans == -1)
        cout << "Element not found" << endl;
    
    else
        cout << "Element is present in arrary at index " << ans << endl;

    return 0;
}




/*
Improve Linear Search Worst-Case Complexity

1. If element Found at last  O(n) to O(1)
2. It is the same as previous method because here we are performing 2 ‘if’ operations in one iteration of the loop and in previous method we performed only 1 ‘if’ operation. This makes both the time complexities same.
   
   Below is the implementation:
*/


#include<bits/stdc++.h>
using namespace std;

void search(vector<int> arr, int search_Element){
	int left = 0;
	int length = arr.size();
	int position = -1;
	int right = length - 1;
	
	// Run loop from 0 to right
	for(left = 0; left <= right;)
	{
		
		// If search_element is found with
		// left variable
		if (arr[left] == search_Element)
		{
			
			position = left;
			cout << "Element found in Array at "
				<< position + 1 << " Position with "
				<< left + 1 << " Attempt";
				
			break;
		}
	
		// If search_element is found with
		// right variable
		if (arr[right] == search_Element)
		{
			position = right;
			cout << "Element found in Array at "
				<< position + 1 << " Position with "
				<< length - right << " Attempt";
				
			break;
		}
		left++;
		right--;
	}

	// If element not found
	if (position == -1)
		cout << "Not found in Array with "
			<< left << " Attempt";
}

// Driver code
int main()
{
	vector<int> arr{ 1, 2, 3, 4, 5 };
	int search_element = 5;
	
	// Function call
	search(arr, search_element);
}