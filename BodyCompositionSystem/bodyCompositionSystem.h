#ifndef BODY_COMPOSITION_SYSTEM_H
#define BODY_COMPOSITION_SYSTEM_H

// invoke user-defined classes
#include "userInputHandles.h"
#include "workoutPlan.h"
#include "banner.h"

#include <iostream>
#include <string>

using namespace std;

UserInputHandles onlyNumeric; // obj to validate user's input - ONLY NUMERIC ALLOWED
WorkoutPlan exercises; // obj to display exercises
Banner displayDesign3; // display a line design

class BodyCompositionSystem {

    public:
        void getUserWeight();
        void getUserHeight();
        void bmiRange();
        void bmiCategory();

        float bmi;  // stores the calculated BMI result
        string result;  // identifies the USER'S BODY COMPOSITION
    
    private:
        // explicitly initialize to zero
        float weight = 0.0f;
        float height = 0.0f;

};

void BodyCompositionSystem::getUserWeight() {

    do {
        cout<<"Please indicate your weight in KILOGRAMS: ";
        cin>>weight;

        onlyNumeric.catchAlphaError();    // catch input error
        displayDesign3.line();   // DESIGN

    } while (onlyNumeric.isInvalid); // repeat until a valid input is received

    getUserHeight(); // SECOND PASS EXECUTION >>>
}

void BodyCompositionSystem::getUserHeight() {

    do {
        cout<<"Please indicate your height in METERS: ";
        cin>>height;

        onlyNumeric.catchAlphaError();
        displayDesign3.line();   // DESIGN

    } while (onlyNumeric.isInvalid); // repeat until a valid input is received

    bmiRange(); // PASS EXECUTION >>>
}

void BodyCompositionSystem::bmiRange() {

    if(height > 0) {    // height must be greater than zero
        bmi=(weight/(height*height)); // calculate user's BMI

        // determine BMI range
        if(bmi<18.5) {
            result="Underweight";
        }else if (bmi<24.9) {
            result="Normalweight";
        }else if (bmi<29.9) {
            result="Overweight";
        }else {
            result="Obese";
        }
        cout<<"Your BMI is: "<<bmi<<endl;   // displays bmi result
    }

    bmiCategory();  // PASS EXECUTION >>>
}

void BodyCompositionSystem::bmiCategory() {

    cout<<"BMI Category: "<<result<<endl;  // displays user's body composition
    
    if (result == "Underweight") {
        exercises.underweightWorkout();
    } else if (result == "Normalweight") {
        exercises.normalweightWorkout();
    } else if (result == "Overweight") {
        exercises.overweightWorkout();
    } else if (result == "Obese") {
        exercises.obeseweightWorkout();
    }
    
}

#endif