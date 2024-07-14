#include <iostream>
#include <vector>
#include <algorithm> // Include for std::reverse
using namespace std;

// Function to rotate an array to the right by K steps
void rotate(vector<int>& nums, int k) {
    int n = nums.size(); // Get the size of the array
    k = k % n; // Calculate effective rotations if k is larger than array size

    // If no rotation needed or array is empty, return early
    if (k == 0 || n == 0) {
        return;
    }

    // Step 1: Reverse the entire array
    reverse(nums.begin(), nums.end());

    // Step 2: Reverse the first k elements
    reverse(nums.begin(), nums.begin() + k);

    // Step 3: Reverse the remaining elements after the first k
    reverse(nums.begin() + k, nums.end());
}

// Function to print the elements of an array
void printArray(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    // Display original array
    cout << "Original array: ";
    printArray(nums);

    // Rotate the array by K steps to the right
    rotate(nums, k);

    // Display rotated array
    cout << "Array rotated by " << k << " steps to the right: ";
    printArray(nums);

    return 0;
}
