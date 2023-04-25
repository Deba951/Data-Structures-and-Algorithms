//Built In Comparator Sort

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector <int> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end()); // NORMAL SORTING Concept.
    for (int i = 0; i < n; i++) cout << v[i] << "  ";

    cout << " " << endl;

    sort(v.begin(), v.end(), greater<int>()); // HERE, greater<int>() IS A 'BUILT IN COMPARATOR'.
    for (int i = 0; i < n; i++) cout << v[i] << "  ";// PRINT THE ARRAY IN DESCENDING ORDER.

    return 0;
}