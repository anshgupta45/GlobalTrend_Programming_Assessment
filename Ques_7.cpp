#include <iostream>
using namespace std;

// Function to compute the sum of digits of a number
int sumOfDigits(int number) {
    int sum = 0;

    // Iterate through each digit of the number
    while (number > 0) {
        // Extract the last digit and add it to sum
        sum += number % 10;

        // Remove the last digit from the number
        number /= 10;
    }

    return sum;
}

int main() {
    // Example usage
    int num = 12345;

    // Calculate sum of digits
    int result = sumOfDigits(num);

    // Output the result
    cout << "Sum of digits of " << num << " is: " << result << endl;

    return 0;
}
