//The frequency of LOWER CASE, UPPER CASE and INTEGER in a given string.

#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
void print_array (long long int arr[26])
{
    for (long long int i = 0; i < 26; i ++)
    {
        cout << "\t" << arr[i];
    }
    cout << endl;
}
void find(char str[100000], long long int lower_case[26], long long int upper_case[26], long long int number[10], long long int value[10])
{
    int j = 0;
    for (long long int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 97 && str[i] <= 122)
        {
            lower_case[str[i] - 'a'] = lower_case[str[i] - 'a'] + 1;
        }
        else if (str[i] >= 65 && str[i] <= 90)
        {
            upper_case[str[i] - 'A'] = upper_case[str[i] - 'A'] + 1;
        }
        else if (str[i] >= 48 && str[i] <= 57)
        {
            value[str[i] - 48] = value[str[i] - 48] + 1;
        }
    }
    cout << "The frequencies of lower case alphabets are from a to z is respectively ::" << endl;
    print_array(lower_case);
    cout << "The frequencies of lower case alphabets are from A to Z is respectively ::" << endl;
    print_array(upper_case);
    cout << "The frequencies of numbers from 0 to 9 are respectively :: " << endl;
    for (int i = 0; i < 10; i ++)
    {
        cout << "\t" << value[i];
    }
    cout << endl;
}
int main()
{
    char str[100000];
    long long int count1= 0, count2 = 0, lower_case[26], upper_case[26], number[10], value[10];
    int t;
    cin >> t;
    cout << "Enter the strings" << endl;
    while (t --)
    {
        fflush (stdin);
        //fgets(str, 100000, stdin);
        scanf("%s", str);
        fflush (stdin);
        fflush (stdout);
        //cout << str;
        fill(lower_case, lower_case + 26, 0);
        fill(upper_case, upper_case + 26, 0);
        fill(value, value + 10, 0);
        find(str, lower_case, upper_case, number, value);
    }
    return 0;
}