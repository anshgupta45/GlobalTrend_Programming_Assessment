#include <iostream>
#include <vector>
#include <limits> // For using INT_MIN and INT_MAX constants
using namespace std;

// Function to find maximum difference between any two elements in array
int maxDifference(const vector<int>& nums) {
    int n = nums.size();
    if (n < 2) {
        return 0; // If array has less than 2 elements, return 0 (no difference possible)
    }

    int minElement = nums[0];
    int maxDiff = nums[1] - nums[0];

    for (int i = 1; i < n; ++i) {
        // Update minimum element found so far
        if (nums[i] < minElement) {
            minElement = nums[i];
        }

        // Update maximum difference found so far
        if (nums[i] - minElement > maxDiff) {
            maxDiff = nums[i] - minElement;
        }
    }

    return maxDiff;
}

int main() {
    // Example usage
    vector<int> nums = {7, 1, 5, 3, 6, 4};

    // Calculate maximum difference between any two elements
    int result = maxDifference(nums);

    // Output the result
    cout << "Maximum difference between any two elements in the array: " << result << endl;

    return 0;
}
