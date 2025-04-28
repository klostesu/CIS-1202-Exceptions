// CIS 1202 Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Sue Klosterman Spring 2025

#include <string>
#include <iostream>
using namespace std;

char character(char start, int offset);


int main()
{
    char inputLetter;
    int inputNumber;

    // Prompt user for inputs

    cout << "Character Offsets Calculation" << endl;
    cout << "______________________________" << endl;

    cout << "Enter a letter: ";
    cin >> inputLetter;

    cout << "Enter a numeric value: ";
    cin >> inputNumber;

    // Call the function and output the result
    char result = character(inputLetter, inputNumber);
    cout << "The new letter is: " << result << endl;

    return 0;
}



char character(char start, int offset) 




{ 
    if (inputLetter ==
    // Convert the character to its ASCII value
    int asciiValue = static_cast<int>(start);

    // Apply addition or subtraction
    int newAsciiValue = asciiValue + offset; 

    // Convert the resulting ASCII value back to a character
    char newLetter = static_cast<char>(newAsciiValue);

    // Return the new character
    return newLetter;
}


