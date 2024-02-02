/*
You are given a binary array 𝑎
 of 𝑛
 elements, a binary array is an array consisting only of 0
s and 1
s.

A blank space is a segment of consecutive elements consisting of only 0
s.

Your task is to find the length of the longest blank space.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤100
) — the length of the array.

The second line of each test case contains 𝑛
 space-separated integers 𝑎𝑖
 (0≤𝑎𝑖≤1
) — the elements of the array.

Output
For each test case, output a single integer — the length of the longest blank space.

Example
inputCopy
5
5
1 0 0 1 0
4
0 1 1 1
1
0
3
1 1 1
9
1 0 0 0 1 0 0 0 1
outputCopy
2
1
1
0
3
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, cnt = 0, max = 0;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++){

            cin >> a[i];

            if (a[i] == 0)
                cnt++;
            
            else{
                
                if (cnt > max)
                    max = cnt;
                
                cnt = 0;
            }
        }
        if (cnt>max)
            max = cnt;
        
        cout << max << endl;
    }
    return 0;
}