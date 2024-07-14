#include <iostream>
#include <unordered_set>
using namespace std;

// Function to find the length of the longest substring without repeating characters
int lengthOfLongestSubstring(string s) {
    int n = s.size(); // Get the length of the input string
    unordered_set<char> visited; // Use a set to keep track of characters in the current window
    int max_len = 0, left = 0, right = 0; // Variables to track maximum length, and window boundaries

    // Loop through the string with a sliding window approach
    while (right < n) {
        // Expand the window to the right until a repeat character is found
        while (right < n && !visited.count(s[right])) {
            visited.insert(s[right]); // Add current character to the set
            right++; // Move the right boundary of the window
        }

        // Calculate the current window size
        max_len = max(max_len, right - left);

        // Slide the window to the right by moving the left boundary
        if (right < n) {
            while (left < right && visited.count(s[right])) {
                visited.erase(s[left]); // Remove characters from the left until the repeat is removed
                left++; // Move the left boundary of the window
            }
        }
    }

    return max_len; // Return the maximum length of substring without repeating characters
}


int main() {
    string s = "abcabcbb"; // Test string
    // Print the result of the function call
    cout << "Length of the longest substring without repeating characters: " << lengthOfLongestSubstring(s) << endl;
    return 0;
}

