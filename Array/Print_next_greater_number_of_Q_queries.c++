/*
Input : arr[] = {3, 4, 2, 7, 5, 8, 10, 6} 
        query indexes = {3, 6, 1}
Output: 8 -1 7 
Explanation : 
For the 1st query index is 3, element is 7 and 
the next greater element at its right is 8 

For the 2nd query index is 6, element is 10 and 
there is no element greater then 10 at right, 
so print -1.

For the 3rd query index is 1, element is 4 and
the next greater element at its right is 7.
*/

/*
Normal Approach: A normal approach will be for every query to move in a loop from index to n and find out the next greater element and print it, but this in worst case will take n iterations, which is a lot if the number of queries are high. 
Time Complexity: O(n^2) 
Auxiliary Space>: O(1)
Efficient Approach: 
An efficient approach is based on next greater element. We store the index of the next greater element in an array and for every query process, answer the query in O(1) that will make it more efficient. 
But to find out the next greater element for every index in array there are two ways. 
One will take o(n^2) and O(n) space which will be to iterate from I+1 to n for each element at index I and find out the ext greater element and store it.
But the more efficient one will be to use stack, where we use indexes to compare and store in next[] the next greater element index.
1) Push the first index to stack. 
2) Pick rest of the indexes one by one and follow following steps in loop. 
….a) Mark the current element as i. 
….b) If stack is not empty, then pop an index from stack and compare a[index] with a[I]. 
….c) If a[I] is greater than the a[index], then a[I] is the next greater element for the a[index]. 
….d) Keep popping from the stack while the popped index element is smaller than a[I]. a[I] becomes the next greater element for all such popped elements 
….g) If a[I] is smaller than the popped index element, then push the popped index back.
3) After the loop in step 2 is over, pop all the index from stack and print -1 as next index for them.
*/

// C++ program to print
// next greater number
// of Q queries
#include <bits/stdc++.h>
using namespace std;

// array to store the next
// greater element index
void next_greatest(int next[],
				int a[], int n)
{
	// use of stl
	// stack in c++
	stack<int> s;

	// push the 0th
	// index to the stack
	s.push(0);

	// traverse in the
	// loop from 1-nth index
	for (int i = 1; i < n; i++)
	{

		// iterate till loop is empty
		while (!s.empty()) {

			// get the topmost
			// index in the stack
			int cur = s.top();

			// if the current element is
			// greater then the top indexth
			// element, then this will be
			// the next greatest index
			// of the top indexth element
			if (a[cur] < a[i])
			{
				
				// initialise the cur
				// index position's
				// next greatest as index
				next[cur] = i;

				// pop the cur index
				// as its greater
				// element has been found
				s.pop();
			}

			// if not greater
			// then break
			else
				break;
		}
		// push the i index so that its
		// next greatest can be found
		s.push(i);
	}

	// iterate for all other
	// index left inside stack
	while (!s.empty())
	{
		int cur = s.top();

		// mark it as -1 as no
		// element in greater
		// then it in right
		next[cur] = -1;

		s.pop();
	}
}

// answers all
// queries in O(1)
int answer_query(int a[], int next[],
				int n, int index)
{
	// stores the next greater
	// element positions
	int position = next[index];

	// if position is -1 then no
	// greater element is at right.
	if (position == -1)
		return -1;

	// if there is a index that
	// has greater element
	// at right then return its
	// value as a[position]
	else
		return a[position];
}

// Driver Code
int main()
{

	int a[] = {3, 4, 2, 7,
			5, 8, 10, 6 };

	int n = sizeof(a) / sizeof(a[0]);

	// initializes the
	// next array as 0
	int next[n] = { 0 };

	// calls the function
	// to pre-calculate
	// the next greatest
	// element indexes
	next_greatest(next, a, n);

	// query 1 answered
	cout << answer_query(a, next, n, 3) << " ";

	// query 2 answered
	cout << answer_query(a, next, n, 6) << " ";

	// query 3 answered
	cout << answer_query(a, next, n, 1) << " ";
}

/*
Output:  
8 -1 7 

Time complexity: max(O(n), O(q)), O(n) for pre-processing the next[] array and O(1) for every query.
Auxiliary Space: O(n)
*/