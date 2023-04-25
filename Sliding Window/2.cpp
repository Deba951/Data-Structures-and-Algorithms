/*
Longest Substring with At Most K Distinct Characters


PROBLEM STATEMENT:

Try Problem
You are given a string 'str' and an integer ‘K’. Your task is to find the length of the largest substring with at most ‘K’ distinct characters.

For Example:
You are given ‘str’ = ‘abbbbbbc’ and ‘K’ = 2, then the substrings that can be formed are [‘abbbbbb’, ‘bbbbbbc’]. Hence the answer is 7.

Input Format:
The first line of input contains the integer ‘T’ representing the number of test cases.

The first line of each test case contains one integer, ‘K’, representing the maximum number of unique characters allowed in the string.

The second line of each test case contains a single string ‘str’ representing the given string.

Output Format:
For each test case, print a single integer representing the length of largest substring that can be formed with at most ‘K’ unique characters.

Print a separate line for each test case.
Constraints:
1 <= T <= 10
1 <= K <= 26
1 <= |str| <= 10^6

The string str will contain only lowercase alphabets.    

Time Limit: 1 sec
Note:
You do not need to print anything. It has already been taken care of. Just implement the function.




APPROACH 1
In this approach, we will traverse through all possible substrings and find all the strings with at most K unique characters, and then we will find the maximum size string of all the substrings.
We create a set uniqueChars for each substring and store the characters for the substring in the set. When the size of uniqueChars is greater than K, then the substring will have more unique characters than K. 

Algorithm:
    Set ans as 0
    Iterate i from 0 to the length of str - 1
    Initialise an empty set uniqueChars
    Iterate j from i to the length of str - 1
    Insert str[j] into the uniqueChars
    If uniqueChars size is greater than K
    Break out of the loop
    Set ans equal to the maximum of ans and j - i + 1
    Finally, return ans
*/



