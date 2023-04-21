/*
The Merge Sort algorithm is a sorting algorithm that is based on the Divide and Conquer paradigm. In this algorithm, the array is initially divided into two equal halves and then they are combined in a sorted manner.

Algorithm:-------->
step 1: start

step 2: declare array and left, right, mid variable

step 3: perform merge function.
    if left > right
        return
    mid= (left+right)/2
    mergesort(array, left, mid)
    mergesort(array, mid+1, right)
    merge(array, left, mid, right)

step 4: Stop

Follow the steps below the solve the problem:----->

MergeSort(arr[], l,  r)
If r > l

--> Find the middle point to divide the array into two halves: 
-> middle m = l + (r – l)/2
--> Call mergeSort for first half:   
-> Call mergeSort(arr, l, m)
--> Call mergeSort for second half:
-> Call mergeSort(arr, m + 1, r)
--> Merge the two halves sorted in steps 2 and 3:
-> Call merge(arr, l, m, r)
*/



//https://practice.geeksforgeeks.org/problems/merge-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        // Your code here
        int n1=(m-l)+1;      // Size of the first partitioned array
        int n2=r-m;         // Size of the second partitioned array

        int L[n1],R[n2];

        for(int i=0; i<n1; i++)
            L[i]=arr[l+i];

        for(int i=0; i<n2; i++)
            R[i]=arr[m+1+i];

        int i=0,j=0,k=l;

        // Merging the two Sorted array, L[] and R[].
        while(i<n1 && j<n2){
            if(L[i]<=R[j]){
                arr[k]=L[i];          //Other way => while().......) {arr[k++]=L[i++];}  
                i++;
            }
            else{
                arr[k]=R[j];      
                j++;
            }
            k++;
        }

        //Possibility that elements of one array has been exhausted but there is still some elements remaining on the other array.
        while(i<n1){
            arr[k]=L[i];
            i++;
            k++;
        }
        while(j<n2){
            arr[k]=R[j];
            j++;
            k++;
        }
    }
    
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        int m=(l+r)/2;
        
        if (r>l){
            mergeSort(arr, l, m);
            mergeSort(arr, m+1, r);
            merge(arr, l, m, r);
        }
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends