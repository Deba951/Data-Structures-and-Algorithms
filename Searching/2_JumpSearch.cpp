/*
Let’s consider the following array: (0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610). The length of the array is 16. The Jump search will find the value of 55 with the following jumps assuming that the block size to be jumped is 4. 
jump 1: Jump from index 0 to index 4; 
jump 2: Jump from index 4 to index 8; 
jump 3: Jump from index 8 to index 12; 
jump 4: Since the element at index 12 is greater than 55, we will jump back a jump to come to index 8. 
jump 5: Perform a linear search from index 8 to get the element 55.

Preference:
If we compare it with linear and binary search then it comes out then it is better than linear search but not better than binary search.
The increasing order of performance is:
linear search  <  jump search  <  binary search

Time Complexity : O(√n) 
Auxiliary Space : O(1)

Important points: 
Works only with sorted arrays.
--> The optimal size of a block to be jumped is (√ n). This makes the time complexity of Jump Search O(√ n).
--> The time complexity of Jump Search is between Linear Search ((O(n)) and Binary Search (O(Log n)).
--> Binary Search is better than Jump Search, but Jump Search has the advantage that we traverse back only once (Binary Search may require up to O(Log n) jumps, consider a situation where the element to be searched is the smallest element or just bigger than the smallest). So, in a system where binary search is costly, we use Jump Search.
*/



// C++ program to implement Jump Search
#include <bits/stdc++.h>
using namespace std;

int jumpSearch(int arr[], int key, int n){
    int jump = sqrt(n);  // Number of elements to be jumped

	//Finding the block.
	int prev = 0;
	while (arr[min(jump, n)-1] < key){
		prev = jump;
		jump += sqrt(n);
		if (prev >= n)
			return -1;
	}

	//Doing a linear search in the block
	while (arr[prev] < key){
		prev++;
        //Element not found
		if (prev == min(jump, n))
			return -1;
	}
	// If element is found
	if (arr[prev] == key)
		return prev;

	return -1;
}

// Driver program to test function
int main(){
	int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610 };
	int key = 55;
	int n = sizeof(arr) / sizeof(arr[0]);
	
	// Find the index of 'key' using Jump Search
	int index = jumpSearch(arr, key, n);

	// Print the index where 'key' is located
	cout << "\nNumber " << key << " is at index " << index;
	return 0;
}