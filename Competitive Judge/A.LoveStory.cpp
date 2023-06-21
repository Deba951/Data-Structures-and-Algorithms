/*
Timur loves codeforces. That's why he has a string 𝑠
 having length 10
 made containing only lowercase Latin letters. Timur wants to know how many indices string 𝑠
 differs from the string "codeforces".

For example string 𝑠=
 "coolforsez" differs from "codeforces" in 4
 indices, shown in bold.

Help Timur by finding the number of indices where string 𝑠
 differs from "codeforces".

Note that you can't reorder the characters in the string 𝑠
.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

Each test case is one line and contains the string 𝑠
, consisting of exactly 10
 lowercase Latin characters.

Output
For each test case, output a single integer — the number of indices where string 𝑠
 differs.

Example
inputCopy
5
coolforsez
cadafurcie
codeforces
paiuforces
forcescode
outputCopy
4
5
0
4
9
*/

//#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
    
int main() {
    int t;
    string str="codeforces";
    cin >> t;
    
    while (t--){
        string s;
        int cnt=0;
        cin >> s;

        for (int i=0; i<s.size(); i++){
            if (s[i]!=str[i]){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
return 0;
}