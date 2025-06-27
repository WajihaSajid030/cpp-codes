#include <iostream>
using namespace std;

int main() {
    int num, reverse = 0;
    cout << "Enter a number: ";
    cin >> num;

    int original = num;


    if (num < 0) {
        num = -num;
    }

    
    while (num > 0) {
        int digit = num % 10;      
        reverse = reverse * 10 + digit; 
        num = num / 10;            
    }

    
    if (original < 0)
        reverse = -reverse; 

    cout << "Reversed number is: " << reverse << endl;

    return 0;
}
