// CIS 1202 Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Sue Klosterman Spring 2025

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

// Function prototype
char character(char start, int offset);

int main() {
    // Test data: vector of pairs (letter, offset)
    vector<pair<char, int>> testData = {
        {'a', 1},
        {'a', -1},//Invalid range should result
        {'Z', -1},
        {"%", 5},  // Invalid character should result
        {10, 5},  // Invalid character should result
        {'A', 32}, // Invalid upper/lower case transitions
    };

    cout << "Calculating Character Offsets - No Upper / Lower Case Transitions" << endl;
    cout << "_________________________________________________________________" << endl;

    for (const auto& test : testData) {
        try {
            char result = character(test.first, test.second);  // Call function
            cout << "character('" << test.first << "', " << test.second
                << ") = '" << result << "'" << endl;
        }
        catch (const char* exceptionMessage) {
            cout << "character('" << test.first << "', " << test.second
                << ") threw an exception: " << exceptionMessage << endl;
        }
    }

    return 0;
}

// Function definition
char character(char start, int offset) {
    // exception for start if its not a letter
   
    if (!isalpha(start)) {
        throw "InvalidCharacterException: Input must be a valid letter.";
    }
    int asciiValue = static_cast<int>(start);
    int newAsciiValue = asciiValue + offset;
    // exception for target if its not a letter
    if (!isalpha(newAsciiValue)) {
        throw "InvalidRangeException: Resulting character is out of range.";
    }
    if ((isupper(start) && !isupper(newAsciiValue)) ||
        (islower(start) && !islower(newAsciiValue))) {
        throw "InvalidRangeException: Upper- and lower-case transitions are not allowed.";
    }

    return static_cast<char>(newAsciiValue);
}