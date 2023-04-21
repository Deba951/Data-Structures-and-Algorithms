/*
Given a sorted array of n uniformly distributed values arr[], write a function to search for a particular element x in the array. 
Linear Search finds the element in O(n) time, Jump Search takes O(√ n) time and Binary Search take O(Log n) time. 
The Interpolation Search is an improvement over Binary Search for instances, where the values in a sorted array are uniformly distributed. Binary Search always goes to the middle element to check. On the other hand, interpolation search may go to different locations according to the value of the key being searched. For example, if the value of the key is closer to the last element, interpolation search is likely to start search toward the end side.


<<<<<<<<<<------------------------------- To find the position to be searched, it uses following formula   ------------------------------>>>>>>>>>>

The idea of formula is to return higher value of pos
when element to be searched is closer to arr[hi]. And
smaller value when closer to arr[lo]
pos = lo + [ (x-arr[lo])*(hi-lo) / (arr[hi]-arr[Lo]) ]

arr[] ==> Array where elements need to be searched
x     ==> Element to be searched
lo    ==> Starting index in arr[]
hi    ==> Ending index in arr[]

<>>>>>>>>>---------------------------------------  The formula for pos can be derived as follows.   --------------------------------------->>>>>>>>>>

Let's assume that the elements of the array are linearly distributed. 

General equation of line : y = m*x + c.
y is the value in the array and x is its index.

Now putting value of lo,hi and x in the equation
arr[hi] = m*hi+c ----(1)
arr[lo] = m*lo+c ----(2)
x = m*pos + c     ----(3)

m = (arr[hi] - arr[lo] )/ (hi - lo)

subtracting eqxn (2) from (3)
x - arr[lo] = m * (pos - lo)
lo + (x - arr[lo])/m = pos
pos = lo + (x - arr[lo]) *(hi - lo)/(arr[hi] - arr[lo])


<<<<---------------------------------------------------------------  Algorithm  --------------------------------------------------------------->>>>>>

Rest of the Interpolation algorithm is the same except the above partition logic. 
Step1: In a loop, calculate the value of “pos” using the probe position formula. 
Step2: If it is a match, return the index of the item, and exit. 
Step3: If the item is less than arr[pos], calculate the probe position of the left sub-array. Otherwise calculate the same in the right sub-array. 
Step4: Repeat until a match is found or the sub-array reduces to zero.
Below is the implementation of algorithm.

<<<<<<<<------------------------------------------------------------------------------------------------------------------------------------->>>>>>>>
*/


// C++ program to implement interpolation search with recursion
#include <bits/stdc++.h>
using namespace std;

// If x is present in arr[0..n-1], then returns
// index of it, else returns -1.
int interpolationSearch(int arr[], int lo, int hi, int x)
{
	int pos;

	// Since array is sorted, an element present
	// in array must be in range defined by corner
	if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {

		// Probing the position with keeping
		// uniform distribution in mind.
		pos = lo
			+ (((double)(hi - lo) / (arr[hi] - arr[lo]))
				* (x - arr[lo]));

		// Condition of target found
		if (arr[pos] == x)
			return pos;

		// If x is larger, x is in right sub array
		if (arr[pos] < x)
			return interpolationSearch(arr, pos + 1, hi, x);

		// If x is smaller, x is in left sub array
		if (arr[pos] > x)
			return interpolationSearch(arr, lo, pos - 1, x);
	}
	return -1;
}

// Driver Code
int main()
{

	// Array of items on which search will be conducted.
	int arr[] = { 10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47 };

	int n = sizeof(arr) / sizeof(arr[0]);

	// Element to be searched
	int x = 18;
	int index = interpolationSearch(arr, 0, n - 1, x);

	// If element was found
	if (index != -1)
		cout << "Element found at index " << index;
	else
		cout << "Element not found.";

	return 0;
}



/*
// Java program to implement interpolation search with recursion
import java.util.*;

class GFG {

	// If x is present in arr[0..n-1], then returns
	// index of it, else returns -1.
	public static int interpolationSearch(int arr[], int lo,
										int hi, int x)
	{
		int pos;

		// Since array is sorted, an element present in array must be in range defined by corner
		
		if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {

			// Probing the position with keeping
			// uniform distribution in mind.
			pos = lo
				+ (((hi - lo) / (arr[hi] - arr[lo]))
					* (x - arr[lo]));

			// Condition of target found
			if (arr[pos] == x)
				return pos;

			// If x is larger, x is in right sub array
			if (arr[pos] < x)
				return interpolationSearch(arr, pos + 1, hi,
										x);

			// If x is smaller, x is in left sub array
			if (arr[pos] > x)
				return interpolationSearch(arr, lo, pos - 1,
										x);
		}
		return -1;
	}

	// Driver Code
	public static void main(String[] args)
	{

		// Array of items on which search will
		// be conducted.
		int arr[] = { 10, 12, 13, 16, 18, 19, 20, 21,
					22, 23, 24, 33, 35, 42, 47 };

		int n = arr.length;

		// Element to be searched
		int x = 18;
		int index = interpolationSearch(arr, 0, n - 1, x);

		// If element was found
		if (index != -1)
			System.out.println("Element found at index "
							+ index);
		else
			System.out.println("Element not found.");
	}
}
*/



/*
----------------------------------------------------------------------------------------------------------------------------------------------------
Interpolation Search is a searching algorithms which works on sorted array.
It works best for arrays where elements are uniformly distributed.
At every iteration it finds the position to search using

			 (key - arr[low]) * (high - low)
pow = low + ----------------------------------
			    (arr[high] - arr[low])

If element at the position is equal to the key, search stops.
If the element at position is greater than the key, search continues in the first part. Otherwise search continues in the second part.
It has best case complexity of O(1), average case complexity of O(log(log n)) and worst case complexity of O(n).

----------------------------------------------------------------------------------------------------------------------------------------------------
PYTHON: 

# Function implementing Interpolation Search
def interpolation_search(arr, key):
    found = False
    low = 0
    high = len(arr) - 1
    while arr[low] <= key <= arr[high] and arr[high] != arr[low]:
        pos = int(low + ((key - arr[low]) * (high - low) / (arr[high] - arr[low])))
        if arr[pos] == key:
            found = True
            print("Found key at index ", pos)
            break
        elif arr[pos] > key:
            high = pos - 1
        else:
            low = pos + 1
 
    if key == arr[low]:
        found = True
        print("Found key at index", low)
 
    if not found:
        print("Could not find the key")
 
 
# Driver function
def main():
    arr = [1, 3, 7, 10, 14, 15, 16, 18, 20, 21, 22, 23, 25, 33, 35, 42, 45, 47, 50, 52]
    key = 33
    interpolation_search(arr, key)
 
 
if __name__ == "__main__":
    main()

----------------------------------------------------------------------------------------------------------------------------------------------------

JAVA:

package algo;
 
public class InterpolationSearch {
    // Method implementing interpolation search
    private static void interpolationSearch(int[] arr, int key) {
        boolean found = false;
        int low = 0;
        int high = arr.length - 1;
        while (key >= arr[low] && key <= arr[high] && arr[high] != arr[low]) {
            int pos = low + ((key - arr[low]) * (high - low) / (arr[high] - arr[low]));
            if (arr[pos] == key) {
                found = true;
                System.out.println("Found key at index " + pos);
                break;
            } else if (arr[pos] > key)
                high = pos - 1;
            else
                low = pos + 1;
        }
        if (key == arr[low]) {
            found = true;
            System.out.println("Found key at index " + low);
        }
        if (!found)
            System.out.println("Could not find the key");
    }
 
    // Driver method
    public static void main(String[] args) {
        int[] arr = {1, 3, 7, 10, 14, 15, 16, 18, 20, 21, 22, 23, 25, 33, 35, 42, 45, 47, 50, 52};
        int key = 33;
        interpolationSearch(arr, key);
    }
}

----------------------------------------------------------------------------------------------------------------------------------------------------

C : 

#include <stdio.h>
 
// Function implementing Interpolation Search
void interpolation_search(int arr[], int arr_len, int key) {
    int found = 0;
    int low = 0;
    int high = arr_len - 1;
    while (key >= arr[low] && key <= arr[high] && arr[high] != arr[low]) {
        int pos = low + ((key - arr[low]) * (high - low) / (arr[high] - arr[low]));
        if (arr[pos] == key) {
            found = 1;
            printf("Found key at index %d\n", pos);
            break;
        } else if (arr[pos] > key)
            high = pos - 1;
        else
            low = pos + 1;
    }
    if (arr[low] == key) {
        found = 1;
        printf("Found key at index %d\n", low);
    }
    if (!found)
        printf("Could not find the key");
}
 
// Driver function
int main() {
    int arr[] = {1, 3, 7, 10, 14, 15, 16, 18, 20, 21, 22, 23, 25, 33, 35, 42, 45, 47, 50, 52};
    int key = 33;
    int arr_len = sizeof(arr) / sizeof(arr[0]);
 
    interpolation_search(arr, arr_len, key);
    return 0;
}

----------------------------------------------------------------------------------------------------------------------------------------------------

*/
