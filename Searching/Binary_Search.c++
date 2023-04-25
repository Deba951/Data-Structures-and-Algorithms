/*
<<<<<<<<********-------------------------------- BINARY SEARCH --------------------------------********>>>>>>>>

Given a sorted array arr[] of n elements, write a function to search a given element x in arr[].
A simple approach is to do a linear search. The time complexity of the above algorithm is O(n). Another approach to perform the same task is using Binary Search. 
Binary Search: Search a sorted array by repeatedly dividing the search interval in half. Begin with an interval covering the whole array. If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half. Otherwise, narrow it to the upper half. Repeatedly check until the value is found or the interval is empty.
 
* The idea of binary search is to use the information that the array is sorted and reduce the time complexity to O(Log n). 

We basically ignore half of the elements just after one comparison.

1.  Compare x with the middle element.
2.  If x matches with the middle element, we return the mid index.
3.  Else If x is greater than the mid element, then x can only lie in the right half subarray after the mid element. So we recur for the right half.
4.  Else (x is smaller) recur for the left half.
*/


// Recursive implementation of Binary Search. A recursive binary search function. It returns location of x in given array arr[l..r] if present, otherwise -1. ------------------------------------------------------------------


#include<iostream>
using namespace std;

void sortArray(int [], int);
int BinarySearch(int [], int, int);

int main()
{
    int n, i, num, pos;
    
    cout << "Enter the Size: " << endl;
    cin >> n;
    cout << "Enter " << n << " Elements: " << endl;


    int arr[n];    
    for(i=0; i<n; i++)
        cin>>arr[i];


    // sorting and printing the array
    sortArray(arr, n);
    cout << "The New Sorted Array is: " << endl;
    for(i=0; i<n; i++)
        cout << arr[i] << " " << endl;


    cout << "Enter Element to be Search: " << endl;
    cin>>num;
    

    pos = BinarySearch(arr, num, n);
    if(pos==0)
        cout << endl << num << " isn't available in the list" << endl;
    else 
        cout << endl << num << " is available at Position " << pos << endl;

    return 0;
}

void sortArray(int arr[], int n)
{
    int i, j, temp;

    for(i=0; i<(n-1); i++)
    {
        for(j=0; j<(n-i-1); j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int BinarySearch(int arr[], int num, int n)
{
    int first, last, middle;
    first = 0;
    last = (n-1);
    middle = (first+last)/2;
    
    while(first <= last)
    {
        if(arr[middle]<num)
            first = middle+1;
        else if(arr[middle]==num)
            return (middle+1);
        else
            last = middle-1;
        middle = (first+last)/2;
    }
    return 0;
}




// -------------------------------------- Recursive implementation another way -----------------------------------

// C++ program to implement recursive Binary Search
#include <bits/stdc++.h>
using namespace std;

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		// If the element is present at the middle
		// itself
		if (arr[mid] == x)
			return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		// Else the element can only be present
		// in right subarray
		return binarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not
	// present in array
	return -1;
}

int main(void)
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	int result = binarySearch(arr, 0, n - 1, x);
	(result == -1) ? cout << "Element is not present in array"
				: cout << "Element is present at index " << result;
	return 0;
}




// ------------------------- Here is recursive implementation with check function  -------------------------------

#include <bits/stdc++.h>
using namespace std;

//define array globally
const int N = 1e6 +4;

int a[N];
int n;//array size

//elememt to be searched in array
int k;

bool check(int dig)
{
	//element at dig position in array
	int ele=a[dig];

	//if k is less than
	//element at dig position
	//then we need to bring our higher ending to dig
	//and then continue further
	if(k<=ele)
	{
		return 1;
	}
	else
	{
	return 0;
	}
}
void binsrch(int lo,int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi)/2;
		if(check(mid))
		{
			hi=mid;
		}
		else
		{
			lo=mid+1;
		}
	}
	//if a[lo] is k
	if(a[lo]==k)
		cout<<"Element found at index "<<lo;// 0 based indexing
	else
		cout<<"Element doesnt exist in array";//element was not in our array

}


int main()
{
	cin>>n;
for(int i=0; i<n; i++)
{
	cin>>a[i];
}
cin>>k;

//it is being given array is sorted
//if not then we have to sort it

//minimum possible point where our k can be is starting index
//so lo=0
//also k cannot be outside of array so end point
//hi=n

binsrch(0,n);

	return 0;
}




// -------------------------------- Iterative implementation of Binary Search ------------------------------------

// C++ program to implement recursive Binary Search
#include <bits/stdc++.h>
using namespace std;

// A iterative binary search function. It returns
// location of x in given array arr[l..r] if present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
	while (l <= r) {
		int m = l + (r - l) / 2;

		// Check if x is present at mid
		if (arr[m] == x)
			return m;

		// If x greater, ignore left half
		if (arr[m] < x)
			l = m + 1;

		// If x is smaller, ignore right half
		else
			r = m - 1;
	}

	// if we reach here, then element was
	// not present
	return -1;
}

int main(void)
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	int result = binarySearch(arr, 0, n - 1, x);
	(result == -1) ? cout << "Element is not present in array"
				: cout << "Element is present at index " << result;
	return 0;
}




/* Time Complexity: 
The time complexity of Binary Search can be written as ----> T(n) = T(n/2) + c 

The above recurrence can be solved either using the Recurrence Tree method or Master method. It falls in case II of the Master Method and the solution of the recurrence is Theta(Logn).

Auxiliary Space: O(1) in case of iterative implementation. In the case of recursive implementation, O(Logn) recursion call stack space.

Algorithmic Paradigm: Decrease and Conquer.

Note:
Here we are using ----> int mid = low + (high – low)/2;

Maybe, you wonder why we are calculating the middle index this way, we can simply add the lower and higher index and divide it by 2.
int mid = (low + high)/2;

But if we calculate the middle index like this means our code is not 100% correct, it contains bugs.

That is, it fails for larger values of int variables low and high. Specifically, it fails if the sum of low and high is greater than the maximum positive int value(231 – 1 ).

The sum overflows to a negative value and the value stays negative when divided by 2. In java, it throws ArrayIndexOutOfBoundException.

int mid = low + (high – low)/2;

So it’s better to use it like this. This bug applies equally to merge sort and other divide and conquer algorithms.

*/