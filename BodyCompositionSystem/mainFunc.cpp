// invoke user-defined classes
#include "bodyCompositionSystem.h"
#include "createAccount.h"
#include "banner.h"

#include <iostream>

using namespace std;

CreateAccount personal; // obj to get user's personal info
BodyCompositionSystem health;  // obj to get user's health profile
Banner display; // obj to view Banner

int main() {
    

    display.displayBanner();    // PRESENTS...
    personal.getPersonalDetails();  // [][][] BEGINS PROGRAM EXECUTION HERE [][][]
    health.getUserWeight();    // FIRST PASS >>>
 
    
    return 0;
}