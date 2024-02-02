#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kadaneAlgorithm(vector<int>& nums) {
    int max_so_far = nums[0];
    int max_ending_here = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        max_ending_here = max(nums[i], max_ending_here + nums[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

int main() {
    vector<int> nums = {1, -2, 3, 4, -1, 2, 1, -5, 4};  // Example input

    int max_sum = kadaneAlgorithm(nums);

    cout << "Maximum subarray sum: " << max_sum << endl;

    return 0;
}
