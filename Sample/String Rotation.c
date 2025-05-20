/*
String Rotation

Problem Description
Rotate a given String in the specified direction by specified magnitude.
After each rotation make a note of the first character of the rotated String, After all rotation are performed the accumulated first character as noted previously will form another string, say FIRSTCHARSTRING.
Check If FIRSTCHARSTRING is an Anagram of any substring of the Original string.
If yes print "YES" otherwise "NO". Input
The first line contains the original string s. The second line contains a single integer q. The ith of the next q lines contains character d[i] denoting direction and integer r[i] denoting the magnitude.

Constraints
1 <= Length of original string <= 30
1<= q <= 10

Output
YES or NO

Explanation
Example 1
Input

carrace
 3
 L 2
 R 2
 L 3

Output

NO

Explanation
 After applying all the rotations the FIRSTCHARSTRING string will be "rcr" which is not anagram of any sub string of original string "carrace".
*/

#include <stdio.h>
#include <string.h>

void left_rotate(char* str, int n, int k)
{
    int i, j, r;
    char temp1,temp2,temp;
    r = k%n;
    temp1 = str[n-1];
    
    for(i=1; i<=r ;i++)
        
        for(j=n-1;j>=0;j--){
            
            if(j!=0){

                temp2=str[j-1];
                str[j-1]=temp1;
                
                temp=temp2;
                temp2=temp1;
                temp1=temp;
            }
           
            else
                str[n-1]=temp1;
        }
}

void right_rotate(char* str, int n, int k)
{
    int i, j, r;
    char temp1,temp2,temp;
    r = k%n;
    temp1 = str[0];
    for(i=1;i<=r;i++)
        for(j=0;j<=n-1;j++){

            if(j!=n-1){

                temp2=str[j+1];
                str[j+1]=temp1;
                
                temp=temp2;
                temp2=temp1;
                temp1=temp;
            }

            else
                str[0]=temp1;
        }
}

int main()
{
    int i,j,q,n;
    int count=0;
    char str[30],temp[15],t;
    char acc[50]="";
    gets(str);
    n=strlen(str);
    scanf("%d",&q);
    getchar();

    for(i=1;i<=q;i++){
        gets(temp);

        for(j=0;j<=strlen(temp)-1;j++){

            if(temp[j]=='l' || temp[j]=='L' || temp[j]=='r' || temp[j]=='R')
                t=temp[j];
            
            else if(temp[j]==' ')
                continue;
            
            else if(temp[j]>=48 && temp[j]<=57 && (t=='l' || t=='L')){
                left_rotate(str,n,(temp[j]-'0'));
                acc[strlen(acc)]=str[0];
            }
            
            else if(temp[j]>=48 && temp[j]<=57 && (t=='r' || t=='R')){
                right_rotate(str,n,(temp[j]-'0'));
                acc[strlen(acc)]=str[0];
            }
        }
    }

    printf("\n%s\n",str);
    printf("\n%s\n",acc);

    return 0;
}