#include <iostream>
#include <string>

using namespace std;

// Function to check if a character is a vowel
bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// Function to reverse a string manually
string reverseString(const string& str) {
    string reversed;
    for (int i = str.length() - 1; i >= 0; i--) {
        reversed += str[i];
    }
    return reversed;
}

// Function to check if a string is a palindrome
bool isPalindrome(const string& str) {
    int left = 0;
    int right = str.length() - 1;
    
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// Function to count vowels, skipping consecutive repeats
int countVowels(const string& str) {
    if (str.empty()) return 0;
    
    int count = 0;
    char lastVowel = '\0'; 
    
    for (char c : str) {
        if (isVowel(c)) {
            if (c != lastVowel) {
                count++;
                lastVowel = c;
            }
        }
    }
    return count;
}

// Function to convert string to lowercase manually
string toLowercase(const string& str) {
    string lower;
    for (char c : str) {
        if (c >= 'A' && c <= 'Z') {
            lower += (c + 32); // convert to lowercase
        } else {
            lower += c;
        }
    }
    return lower;
}

int main() {
    string input;
    
    cout << "Enter a single string:";
    getline(cin, input);
    
    // Check for whitespace
    bool hasSpace = false;
    for (char c : input) {
        if (isspace(c)) {
            hasSpace = true;
            break;
        }
    }
    
    if (hasSpace) {
        cout << "Warning: Input contains whitespace. Exiting." << endl;
        return 0;
    }
    
    // Process the string
    string lowercaseStr = toLowercase(input);
    string reversedStr = reverseString(lowercaseStr);
    int vowelCount = countVowels(lowercaseStr);
    bool palindrome = isPalindrome(lowercaseStr);
    

    cout << "\n=== String Analysis Report ===" << endl;
    cout << "Original: " << input << endl;
    cout << "Reversed: " << reversedStr << endl;
    cout << "Length: " << lowercaseStr.length() << endl;
    cout << "Vowels: " << vowelCount << endl;
    cout << "Palindrome: " << (palindrome ? "YES" : "NO") << endl;
    
    return 0;
}