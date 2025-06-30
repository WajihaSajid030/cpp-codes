#include <iostream>
#include <string>
using namespace std;

void printBanner(string message) {
    cout << "        " << message << endl;

}

int factorial(int n) {
    if (n > 12) {
        cout << "Warning: Input too large, may cause integer overflow." << endl;
        return -1;
    }
    if (n < 0)
        return -1;
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}


int customMax(int a, int b, int c) {
    if (a == b && b == c)
        return 0;

    int maxVal = max(a, max(b, c));

    if (a == b && a == maxVal)
        return a + b;
    if (a == c && a == maxVal)
        return a + c;
    if (b == c && b == maxVal)
        return b + c;

    return maxVal;
}

int main() {
    int n, a, b, c;

    printBanner("Factorial Task");
    cout << "Enter an integer for factorial: ";
    cin >> n;
    int factResult = factorial(n);

    printBanner("Custom Max Task");
    cout << "Enter three integers: ";
    cin >> a >> b >> c;
    int maxResult = customMax(a, b, c);

    printBanner("Results");
    if (factResult != -1)
        cout << "Factorial of " << n << " is: " << factResult << endl;
    else
        cout << "Factorial calculation failed due to input constraints.\n";

    cout << "Custom max result for (" << a << ", " << b << ", " << c << ") is: " << maxResult << endl;

    return 0;
}
