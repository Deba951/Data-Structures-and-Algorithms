/*
The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.
1) The subarray which is already sorted. 
2) Remaining subarray which is unsorted.
In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray. 

Time Complexity: O(n2) as there are two nested loops.
Auxiliary Space: O(1) 
The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation.
*/


//https://practice.geeksforgeeks.org/problems/selection-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


// } Driver Code Ends
class Solution
{
    public:
    	int  select(int arr[], int i)
    	{
            // code here such that selectionSort() sorts arr[]
    	}
	
    	void selectionSort(int arr[], int n)
    	{
    	    //code here
    	    for (int i=0; i<n; ++i){
                int min=arr[i];
                int mini=i;        
                for (int j=i; j<n; ++j){
                    if(arr[j]<min){
                        min=arr[j];
                        mini=j;
                    }
                }
                swap(arr[i],arr[mini]);
        }
    }
};

//{ Driver Code Starts.
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[1000],n,T,i;
  
    scanf("%d",&T);
    
    while(T--){
        
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      
    Solution ob;  
    ob.selectionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends



/* 
Stability: The default implementation is not stable. However, it can be made stable.

A sorting algorithm is said to be stable if two objects with equal or same keys appear in the same order in sorted output as they appear in the input array to be sorted.
Any comparison based sorting algorithm which is not stable by nature can be modified to be stable by changing the key comparison operation so that the comparison of two keys considers position as a factor for objects with equal key or by tweaking it in a way such that its meaning doesn’t change and it becomes stable as well. Example:-->
 
Note: Subscripts are only used for understanding the concept.

Input : 4A 5 3 2 4B 1
Output : 1 2 3 4B 4A 5

Stable Selection Sort would have produced
Output : 1 2 3 4A 4B 5
*/