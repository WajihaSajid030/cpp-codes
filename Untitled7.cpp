#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 5;
int getSum(int arr[]) {
    int total = 0;
    for (int i = 0; i < SIZE; i++) {
        total = total + arr[i];
    }
    return total;
}
int getMaxIndex(int arr[]) {
    int maxIndex = 0;
    for (int i = 1; i < SIZE; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}
int getMinIndex(int arr[]) {
    int minIndex = 0;
    for (int i = 1; i < SIZE; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}
double getAverage(int arr[]) {
    int total = getSum(arr);
    return (double) total / SIZE;
}
void reorderEvenOdd(int arr[], int reordered[]) {
    int index = 0;

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] % 2 == 0) {
            reordered[index] = arr[i];
            index++;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] % 2 != 0) {
            reordered[index] = arr[i];
            index++;
        }
    }
}

int main() {
    int numbers[SIZE];
    int reordered[SIZE];

    cout << "Enter 5 numbers: ";
    for (int i = 0; i < SIZE; i++) {
        cin >> numbers[i];
    }

    int sum = getSum(numbers);
    double avg = getAverage(numbers);
    int maxPos = getMaxIndex(numbers);
    int minPos = getMinIndex(numbers);

    reorderEvenOdd(numbers, reordered);

    cout << endl << "=== Analyzing Array ===" << endl;
    cout << "Sum = " << sum << endl;
    cout << fixed << setprecision(2);
    cout << "Average = " << avg << endl;
    cout << "Maximum = " << numbers[maxPos] << " at position " << (maxPos + 1) << endl;
    cout << "Minimum = " << numbers[minPos] << " at position " << (minPos + 1) << endl;

    cout << endl << "Reordered Array: ";
    for (int i = 0; i < SIZE; i++) {
        cout << reordered[i] << " ";
    }
    cout << endl;

    return 0;
}
