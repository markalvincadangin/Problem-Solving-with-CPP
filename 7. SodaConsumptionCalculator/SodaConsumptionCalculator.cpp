//File Name: SodaConsumptionCalculator.cpp
//Author: Mark Alvin Cadangin
//Email Address: markalvin.cadangin@wvsu.edu.ph
//Assignment Number: 
//Description: This program calculates the amount of soda consumed by the user and determines if the consumption level 
//             is within a healthy range. It prompts the user to enter the number of soda cans consumed per day and 
//             calculates the total consumption over a specified period. Based on the total consumption, the program 
//             provides feedback on whether the user's soda consumption is potentially harmful to their health.
//Last Changed: September 16, 2024

#include <iostream>
using namespace std;

double ConvertPoundsToGrams(double DieterWeightInPounds);
double CalculateDieterMaxArtificialSweetener(double MouseMaxArtificialSweetener, double MouseWeight, double DieterWeightInGrams);
double CalculateDieterMaxSoda(double DieterMaxArtificialSweetener);

int main() {
    const double MouseMaxArtificialSweetener = 5.0;
    const double MouseWeight = 35.0;
    double DieterMaxArtificialSweetener = 0;
    double DieterWeightInGrams = 0;
    double DieterWeightInPounds = 0;
    double DieterMaxSoda = 0;
    string response;

    do{
        cout << "Enter at what weight you would like to stop dieting (in pounds): ";
        cin >> DieterWeightInPounds;
        while(DieterWeightInPounds <= 0){
            cout << "Invalid weight. Please enter a valid weight (in pounds): ";
            cin >> DieterWeightInPounds;
        }

        DieterWeightInGrams = ConvertPoundsToGrams(DieterWeightInPounds);
        DieterMaxArtificialSweetener = CalculateDieterMaxArtificialSweetener(MouseMaxArtificialSweetener, MouseWeight, DieterWeightInGrams);
        DieterMaxSoda = CalculateDieterMaxSoda(DieterMaxArtificialSweetener);

        cout << "You can drink " << static_cast<int>(DieterMaxSoda) << " cans of soda without dying." << endl;

        cout << "\nWould you like to enter another weight? (Yes or No): ";
        cin >> response;
        while(response != "Yes" && response != "No" && response != "yes" && response != "no" && response != "YES" && response != "NO"){
            cout << "Invalid response. Please enter a valid response (Yes or No): ";
            cin >> response;
        }
    } while(response == "Yes" || response == "yes" || response == "YES");



    return 0;
}

double ConvertPoundsToGrams(double DieterWeightInPounds){

    double DieterWeightInGrams = DieterWeightInPounds * (45400/100);
    return DieterWeightInGrams;
}

double CalculateDieterMaxArtificialSweetener(double MouseMaxArtificialSweetener, double MouseWeight, double DieterWeightInGrams){

    double DieterMaxArtificialSweetener = (DieterWeightInGrams / MouseWeight) * MouseMaxArtificialSweetener;
    return DieterMaxArtificialSweetener;
}

double CalculateDieterMaxSoda(double DieterMaxArtificialSweetener){

    double SodaWeight = 350;
    double SodaSweetener = ((SodaWeight / 10) * 0.01);

    double DieterMaxSoda = DieterMaxArtificialSweetener / SodaSweetener;
    return DieterMaxSoda;
}
