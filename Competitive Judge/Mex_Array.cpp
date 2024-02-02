#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;

void sol(){
    int size;
    cin >> size;

    unordered_map<int, int> frequency_map;
    multiset<int> number_set;
    vector<int> missing_numbers;

    for (int i=0; i<size; i++) {
        int num;
        cin >> num;
        frequency_map[num]++;
        number_set.insert(num);
    }

    int remaining_count = size;

    while (remaining_count > 0) {
        
        for (int i=0; i<size+5; i++) {
            
            if (frequency_map[i] > 0) {
                frequency_map[i]--;
                remaining_count--;
            } else {
                if (i == 0) {
                    while (remaining_count--) {
                        missing_numbers.push_back(0);
                    }
                    break;
                }
                missing_numbers.push_back(i);
                break;
            }
        }
    }

    cout << missing_numbers.size() << endl;
    for (auto missing_num : missing_numbers) {
        cout << missing_num << " ";
    }
    cout << endl;
}

int main(){
    
    int test_cases;
    cin >> test_cases;

    while (test_cases--)
        sol();
        
    return 0;
}