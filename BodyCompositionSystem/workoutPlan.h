#ifndef WORKOUT_PLAN_H
#define WORKOUT_PLAN_H

#include "banner.h"

#include <iostream>
#include <vector>   // stores the same variable data type - 'string' in this case
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

Banner displayDesign2; // display a line design

class WorkoutPlan {

    public:
        WorkoutPlan();  // Explicitly declare a constructor in order to create a random seed generator
            
        void underweightWorkout();
        void normalweightWorkout();
        void overweightWorkout();
        void obeseweightWorkout();

        string getRandomCardioExercise();   // get only 1 cardio exercise from the given

        // displays a weekly workout plan
        void displayWorkoutPlan(const vector<string>&upperLowerExercises, const vector<string>&cardioExercises, int sets, int reps);
    
    private:
        // declare as a static variable to retain its value when invoke
        static vector<string> upperLowerExercises;
        static vector<string> cardioExercises;
        static vector<string> days;

};

WorkoutPlan::WorkoutPlan() {
    srand(static_cast<unsigned int>(time(0)));  // Seed random number generator with current time
}


vector<string> WorkoutPlan:: upperLowerExercises = {
    "Push-ups", "Rows", "Overhead Press", "Bicep Curls", "Tricep Extensions",
    "Squats", "Lunges", "Deadlifts", "Calf Raises", "Glute Bridges" 
    };
vector<string> WorkoutPlan::cardioExercises = {"Cycling", "Jogging", "Jumping Jacks", "Boxing"};
vector<string> WorkoutPlan::days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};


string WorkoutPlan::getRandomCardioExercise() {
    int index = rand() % cardioExercises.size();
    return cardioExercises.at(index);
}

void WorkoutPlan::underweightWorkout() {
    int sets = 3;
    int reps = 12;
    displayWorkoutPlan(upperLowerExercises, cardioExercises, sets, reps);
}

void WorkoutPlan::normalweightWorkout() {
    int sets = 3;
    int reps = 10;
    displayWorkoutPlan(upperLowerExercises, cardioExercises, sets, reps);
}   

void WorkoutPlan::overweightWorkout() {
    int sets = 2;
    int reps = 10;
    displayWorkoutPlan(upperLowerExercises, cardioExercises, sets, reps);
}

void WorkoutPlan::obeseweightWorkout() {
    int sets = 2;
    int reps = 8;
    displayWorkoutPlan(upperLowerExercises, cardioExercises, sets, reps);
}

void WorkoutPlan::displayWorkoutPlan(const vector<string>& upperLowerExercises, const vector<string>& cardioExercises, int sets, int reps) {
    
    int numUpperLowerExercises = upperLowerExercises.size() -5;    // get size to know limit
    
    for (const auto& day : days) { // list comprehension - 7 days in a week
        cout<<"\n"<<day<<" Workout Plan:\n";
        
        // Display 1 cardio exercise
        string cardioExercise = getRandomCardioExercise();
        cout<<"Perform "<<sets<<" sets of "<<reps<<" reps "<<cardioExercise<<"\n";

        // Display upper and lower body exercises
        for (int i = 0; i < numUpperLowerExercises - 1; ++i) {  
            int index = rand() % numUpperLowerExercises ;   // get 1 exercise per iteration
            cout<<"Perform "<<sets<<" sets of "<<reps<<" reps "<<upperLowerExercises[index] << "\n";
        }
        displayDesign2.line();   // DESIGN 
    }

}

#endif