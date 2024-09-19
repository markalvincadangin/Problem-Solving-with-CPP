//File Name: CarpetPriceCalculator.cpp
//Author: Mark Alvin Cadangin
//Email Address: markalvin.cadangin@wvsu.edu.ph
//Assignment Number: 
//Description: Program to calculate the price of a carpet based on its length in meters.
//Last Changed: September 16, 2024

#include <iostream>
using namespace std;

int main() {

    double length, totalPrice;
    const double pricePerMeter = 2.75;
    string response;

    do{
        cout << "Enter the length of the carpet in meters: ";
        cin >> length;
        while(length <= 0){
            cout << "Invalid length. Please enter a valid length (in meters): ";
            cin >> length;
        }

        if (length > 10){
            totalPrice = pricePerMeter * length - ((length - 10) * pricePerMeter * 0.15);
        } else {
            totalPrice = pricePerMeter * length;
        }
        

        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        cout << "The total price of the carpet is $" << totalPrice << endl;

        cout << "\nWould you like to enter another length? (Yes or No): ";
        cin >> response;
        while(response != "Yes" && response != "No" && response != "yes" && response != "no" && response != "YES" && response != "NO"){
            cout << "Invalid response. Please enter a valid response (Yes or No): ";
            cin >> response;
        }
    } while(response == "Yes" || response == "yes" || response == "YES");

    return 0;
}