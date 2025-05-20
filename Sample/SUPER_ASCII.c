/*
Super ASCII String Checker | TCS CodeVita
In the Byteland country, a string S is said to super ASCII string if and only if the count of each character in the string is equal to its ASCII value. In the Byteland country ASCII code of ‘a’ is 1, ‘b’ is 2, …, ‘z’ is 26. The task is to find out whether the given string is a super ASCII string or not. If true, then print “Yes” otherwise print “No”.

Examples:

Input: S = “bba” 
Output: Yes
Explanation:
The count of character ‘b’ is 2 and the ASCII value of ‘b’ is also 2.
The count of character ‘a’ is 1. and the ASCII value of ‘a’ is also 1. 
Hence, string “bba” is super ASCII String.

Input: S = “ssba”
Output: No
Explanation:
The count of character ‘s’ is 2 and the ASCII value of ‘s’ is 19.
The count of character ‘b’ is 1. and the ASCII value of ‘b’ is 2.
Hence, string “ssba” is not a super ASCII String.

Now, using this formula, the frequency count of each character in the string can be compared with its ASCII value. Follow the below steps to solve the problem:

Initialize an array to store the frequency count of each character of the string.
Traverse the string S and increment the frequency count of each character by 1.
Again, traverse the string S and check if any character has non-zero frequency and is not equal to its ASCII value then print “No”.
After the above steps if there doesn’t any such character in the above step then print “Yes”.

Below is the implementation of the above approach:




PYTHON:

import string #for accessing alphabets

dicti = {}
a = []

#creating a list with the alphabets
for i in string.ascii_lowercase:
	a.append(i)

#creating a dictionary for the alphabets and correpondind ascii code
for i in string.ascii_lowercase:
	for j in range (1,27):
		if (a.index(i)+1) == j: #if the number is equal to the position of the alphabet
			dicti[i] = j	 #in the list, then the number will be ascii code for the
			break			 #aplhabet in the dictionary

s = 'bba'
t = True #t is initialized as true

for i in s:
	if s.count(i) != dicti[i]: #if any of the alphabet count is not equal to its
		t = False			 #corresponding ascii code in the dictionary, t will be false

if t:
	print("Yes")		 #printing yes if t remains true after checking all alphabets
else:
	print("No")




JAVA: 

// Java program for the above approach
import java.io.*;
import java.util.*;

class GFG{
	
// Function to check whether the
// string is super ASCII or not
public static void checkSuperASCII(String s)
{
	
	// Stores the frequency count
	// of characters 'a' to 'z'
	int b[] = new int[26];

	// Traverse the string
	for(int i = 0; i < s.length(); i++)
	{
		
		// AscASCIIii value of the
		// current character
		int index = (int)s.charAt(i) - 97 + 1;
		
		// Count frequency of each
		// character in the string
		b[index - 1]++;
	}

	// Traverse the string
	for(int i = 0; i < s.length(); i++)
	{
		
		// ASCII value of the current
		// character
		int index = (int)s.charAt(i) - 97 + 1;
		
		// Check if the frequency of
		// each character in string
		// is same as ASCII code or not
		if (b[index - 1] != index)
		{
			System.out.println("No");
			return;
		}
	}
	
	// Else print "Yes"
	System.out.println("Yes");
}

// Driver Code
public static void main(String args[])
{
	
	// Given string S
	String s = "bba";
	
	// Function Call
	checkSuperASCII(s);
}
}

*/

#include <stdio.h>
int main()
{
    int counts[26], t, c;
    scanf("%d", &t);
    char str[10000];
    int arr[t];
    int k = 0;
    while (t --)
    {
        scanf("%s", str);
        fflush(stdin);
        int cnt = 0;
        c = 0;
        for (int i = 0; i < 26; i ++)
        {
            counts[i] = 0;
        }
        for (int i = 0; str[i] != '\0'; i ++)
       {
           counts[str[i] - 'a'] = counts[str[i] - 'a'] + 1;
       }
       for (int i = 0; i < 26; i ++)
       {
           if (counts[i] > 0)
           {
               cnt ++;
           }
       }
       for (int i = 0; i < 26; i ++)
       {
           if (counts[i] == i + 1)
           {
               c ++;
           }
       }
        //printf("%d\n", cnt);
        if (c == cnt)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;1
}


/*
// C program for the above approach
#include <stdio.h>
#include <string.h>

// Function to check whether the
// string is super ASCII or not
void checkSuperASCII(char s[])
{
	// Stores the frequency count
	// of characters 'a' to 'z'
	int b[26] = { 0 };

	// Traverse the string
	for (int i = 0; i < strlen(s); i++) {

		// AscASCIIii value of the
		// current character
		int index = (int)s[i] - 97 + 1;

		// Count frequency of each
		// character in the string
		b[index - 1]++;
	}

	// Traverse the string
	for (int i = 0; i < strlen(s); i++) {

		// ASCII value of the current
		// character
		int index = (int)s[i] - 97 + 1;

		// Check if the frequency of
		// each character in string
		// is same as ASCII code or not
		if (b[index - 1] != index) {
			printf("No");
			return;
		}
	}

	// Else print "Yes"
	printf("Yes");
}

// Driver Code
int main()
{
	// Given string S
	char s[] = "bba";

	// Function Call
	checkSuperASCII(s);
	return 0;
}

*/