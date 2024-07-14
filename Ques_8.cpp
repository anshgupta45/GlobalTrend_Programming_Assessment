#include <iostream>
using namespace std;

// Function to compute the Greatest Common Divisor (GCD) using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    // Example usage
    int num1 = 24;
    int num2 = 36;

    // Calculate GCD of num1 and num2
    int result = gcd(num1, num2);

    // Output the result
    cout << "GCD of " << num1 << " and " << num2 << " is: " << result << endl;

    return 0;
}
