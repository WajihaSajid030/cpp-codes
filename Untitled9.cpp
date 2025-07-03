#include <iostream>
#include <cstdlib>

using namespace std;

// Function prototypes
void conditionalSwap(int* x, int* y);
void printArrayViaPointer(int* arr, int size);
int* findFirstEven(int* arr, int size);
void incrementOddsByAddress(int* arr, int size);
bool isOdd(int n);

int main() {
    int a, b;
    int arr[5];

    cout << "Enter two integers (a and b): ";
    cin >> a >> b;

   
    cout << "Enter 5 integers for the array: ";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    cout << "\n=== Pointer Logic Execution ===" << endl;

    
    cout << "Before Swap: a = " << a << ", b = " << b << endl;

    conditionalSwap(&a, &b);
    cout << "After Swap: a = " << a << ", b = " << b << endl;

    cout << "\nArray Elements (value @ address):" << endl;
    printArrayViaPointer(arr, 5);
    int* firstEven = findFirstEven(arr, 5);
    if (firstEven != nullptr) {
        cout << "\nFirst even number: " << *firstEven << " @ " << firstEven << endl;
    } else {
        cout << "\nNo even numbers found in the array." << endl;
    }
    incrementOddsByAddress(arr, 5);
    cout << "\nArray after incrementing odd numbers:" << endl;
    printArrayViaPointer(arr, 5);

    return 0;
}

void conditionalSwap(int* x, int* y) {
    int* temp = new int;
    if (abs(*x - *y) > 10) {
        *temp = *x;
        *x = *y;
        *y = *temp;
    }
    delete temp;
}

void printArrayViaPointer(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << " - " << *(arr + i) << " @ " << (arr + i) << endl;
    }
}

int* findFirstEven(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        if (*(arr + i) % 2 == 0) {
            return (arr + i);
        }
    }
    return nullptr;
}

void incrementOddsByAddress(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        if (isOdd(*(arr + i))) {
            (*(arr + i))++;
        }
    }
}

bool isOdd(int n) {
    return n % 2 != 0;
}