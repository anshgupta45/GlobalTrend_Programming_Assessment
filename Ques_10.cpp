#include <iostream>
#include <string>
using namespace std;

// Function to check if a string contains only alphabetic characters
bool containsOnlyAlphabets(const string& str) {
    // Iterate through each character in the string
    for (char c : str) {
        // Check if the character is not an alphabet
        if (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z')) {
            return false; // Return false immediately if non-alphabetic character found
        }
    }
    return true; // Return true if all characters are alphabetic
}

int main() {
    // Example usage
    string str1 = "HelloWorld";   // Contains only alphabetic characters
    string str2 = "Hello123";     // Contains non-alphabetic characters

    // Check if str1 contains only alphabetic characters
    bool result1 = containsOnlyAlphabets(str1);
    cout << "String '" << str1 << "' contains only alphabetic characters: " << (result1 ? "true" : "false") << endl;

    // Check if str2 contains only alphabetic characters
    bool result2 = containsOnlyAlphabets(str2);
    cout << "String '" << str2 << "' contains only alphabetic characters: " << (result2 ? "true" : "false") << endl;

    return 0;
}
