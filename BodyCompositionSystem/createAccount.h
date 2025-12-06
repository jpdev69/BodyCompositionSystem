#ifndef CREATE_ACCOUNT_H
#define CREATE_ACCOUNT_H

// invoke user-defined classes
#include "userInputHandles.h"
#include "banner.h"

#include <iostream>
#include <string>

using namespace std;

UserInputHandles onlyAlpha; // obj to validate user's input - ONLY ALPHA ALLOWED
UserInputHandles onlyNum; // obj to validate user's input - ONLY NUMERIC ALLOWED
Banner displayDesign1; // display a line design

class CreateAccount {

    public:
        void getPersonalDetails();
    
    private:
        string name, address;
        int age;
        char input;

};

void CreateAccount::getPersonalDetails() {

    do {
        cout<<"PLEASE INDICATE YOUR NAME: "<<endl;
        getline(cin, name); // GET WHOLE SET OF INPUT
        
        onlyAlpha.catchNumericError(name);
        displayDesign1.line();   // DESIGN

    } while(onlyAlpha.isInvalid);
    
    do {
        cout<<"SPECIFY WHERE YOU LIVE: "<<endl;
        getline(cin, address); // GET WHOLE SET OF INPUT

        onlyAlpha.catchNumericError(address);
        displayDesign1.line();   // DESIGN

    } while(onlyAlpha.isInvalid);

    do {
        cout<<"HOW OLD ARE YOU: "<<endl;
        cin>>age; // GET NUMERIC INPUT
        
        onlyNum.catchAlphaError();
        displayDesign1.line();   // DESIGN

    } while(onlyNum.isInvalid);

    displayDesign1.line();   // DESIGN
    cout<<"NAME: "<<name<<"\n"<<"ADDRESS: "<<address<<"\n"<<"AGE: "<<age<<endl; // DISPLAY RECENT INPUT FOR CREDENTIALS
    displayDesign1.line();   // DESIGN

}

#endif