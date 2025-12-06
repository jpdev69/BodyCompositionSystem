#ifndef USER_INPUT_HANDLES_H
#define USER_INPUT_HANDLES_H

#include <iostream>
#include <string>
#include <cctype>   // related to 'character'
#include <limits>   // related to 'numerical' calculations

using namespace std;

class UserInputHandles {

    public:
        void catchAlphaError(); // handles invalid alphabet from the user
        void catchNumericError(string str);   // handles invalid numeric from the user

        bool isInvalid; // a switch for a loop

};

void UserInputHandles::catchAlphaError() {
    
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');    // ONLY ALLOW NUMERIC AS INPUT,
        cout << "Invalid input. Please re-enter a numeric value. \n";   // OTHERWISE..

        isInvalid = true;
    } else {
        isInvalid = false;
    }

}

void UserInputHandles::catchNumericError(string str) {

    for(char c : str) { // ONLY ALLOW CHARACTERS AS INPUT
        if(!isalpha(c) && c != ' ') {   // detect if a single instance of non-string and whitespace is encountered
            cout<<"Invalid input. Please re-enter a character value. \n";
            
            isInvalid = true;
            break;
        } else {
            isInvalid = false;
        }
    }
    isInvalid;  // ignore if input is an empty string

}

#endif