// https://leetcode.com/problems/combination-sum/description/

// #include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    // Helper function to find all combinations that sum up to the target
    void findCombination(int index, int target, vector<int> &arr, vector<vector<int>> &result, vector<int> &current) {
        // Base case: if we have reached the end of the array
        if (index == arr.size()) {
            // If the current combination sums up to the target, add it to the result
            if (target == 0) {
                result.push_back(current);
            }
            return;
        }
        
        // Pick the element if it is less than or equal to the target
        if (arr[index] <= target) {
            current.push_back(arr[index]);  // Include the current element in the combination
            // Recur with the same index and reduced target
            findCombination(index, target - arr[index], arr, result, current);
            current.pop_back();  // Backtrack by removing the element from the current combination
        }

        // Move to the next element
        findCombination(index + 1, target, arr, result, current);
    }

    // Main function to find all unique combinations of candidates that sum up to the target
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        findCombination(0, target, candidates, result, current);
        return result;
    }
};

int main() {
    Solution solver;
    vector<int> candidates = {2, 3, 6, 7};  // Example input
    int target = 7;  // Example target

    // Find all combinations that sum up to the target
    vector<vector<int>> combinations = solver.combinationSum(candidates, target);
    
    // Output the result
    cout << "Combinations are: " << endl;
    for (const auto &combination : combinations) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}



