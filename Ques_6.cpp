#include <iostream>
using namespace std;

// Function to calculate factorial of a number
int factorial(int n) {
    // Base case: factorial of 0 is 1
    if (n == 0 || n == 1) {
        return 1;
    } else {
        // Recursive case: n! = n * (n-1)!
        return n * factorial(n - 1);
    }
}

int main() {
    
    int number = 5; // Compute factorial of 5

    // Calculate factorial
    int result = factorial(number);

    // Output the result
    cout << "Factorial of " << number << " is: " << result << endl;

    return 0;
}
