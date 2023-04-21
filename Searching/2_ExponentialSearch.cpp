/*
The name of this searching algorithm may be misleading as it works in O(Log n) time. The name comes from the way it searches an element.

Exponential search involves two steps:
1. Find range where element is present
2. Do Binary Search in above found range.

How to find the range where element may be present? 
The idea is to start with subarray size 1, compare its last element with x, then try size 2, then 4 and so on until last element of a subarray is not greater. 
Once we find an index i (after repeated doubling of i), we know that the element must be present between i/2 and i (Why i/2? because we could not find a greater value in previous iteration)
*/


#include <bits/stdc++.h>
using namespace std;
 
int binarySearch(int arr[], int, int, int);
 
// Returns position of first occurrence of x in array
int exponentialSearch(int arr[], int n, int x)
{
    // If x is present at first location itself
    if (arr[0] == x)
        return 0;
 
    // Find range for binary search by repeated doubling
    int i = 1;
    while (i < n && arr[i] <= x)
        i = i*2;
 
    //  Call binary search for the found range.
    return binarySearch(arr, i/2,min(i, n-1), x);
}
 
// A recursive binary search function. It returns location of x in  given array arr[l..r] is present, otherwise return -1.

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l)/2;
 
        // If the element is present at the middle itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then it can only be present n left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid-1, x);
 
        // Else the element can only be present in right subarray
        return binarySearch(arr, mid+1, r, x);
    }
 
    // We reach here when element is not present in array
    return -1;
}

int main(void)
{
        int n;
        cout << "Enter the number of elements" << endl;
        cin >> n;

        int arr[n];
        cout << "Enter the elements in the array: " << endl;
        for (int i = 0; i < n; i++) {
                cin >> arr[i];
        }
		
		sort (arr, arr+n);

		cout << "\n\n" << "Sorted list: " << endl;
		for (int i = 0; i < n; i++) {
                cout << arr[i] << endl;
        }
        
		//int n = sizeof(arr)/ sizeof(arr[0]);
        int x ;
        cout << "Enter the element to be searched:" << endl;
        cin >> x;
        int result = exponentialSearch(arr, n, x);
        (result == -1)? cout <<"Element is not present in array" : cout <<"Element is present at index " << result << ", that is at position" << result+1 << " in the sorted list of elements insertede";
        return 0;
}



/*
Time Complexity : O(Log n) 
Auxiliary Space : The above implementation of Binary Search is recursive and requires O(Log n) space. With iterative Binary Search, we need only O(1) space.
Applications of Exponential Search: 

Exponential Binary Search is particularly useful for unbounded searches, where size of array is infinite. Please refer Unbounded Binary Search for an example.
It works better than Binary Search for bounded arrays, and also when the element to be searched is closer to the first element.
*/