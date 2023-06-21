#include <iostream>
#include <algorithm>

using namespace std;

int kadaneAlgorithm(int arr[], int n) {
    int max_so_far = arr[0];
    int max_ending_here = arr[0];

    for (int i = 1; i < n; i++) {
        max_ending_here = max(arr[i], max_ending_here + arr[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

int main() {
    int nums[] = {1, -2, 3, 4, -1, 2, 1, -5, 4};  // Example input
    int size = sizeof(nums) / sizeof(nums[0]);

    int max_sum = kadaneAlgorithm(nums, size);

    cout << "Maximum subarray sum: " << max_sum << endl;

    return 0;
}
