//File Name: CallCostCalculator.cpp
//Author: Mark Alvin Cadangin
//Email Address: markalvin.cadangin@wvsu.edu.ph
//Assignment Number: 
//Description: This program calculates the cost of a call based on the day and time it was made.
//Last Changed: September 16, 2024

#include <iostream>
#include <limits>
using namespace std;

int main(){

    string day;
    int hour = 0, minutes = 0, duration;
    double totalcost = 0;
    char colon = ':';
    string repeat;

    do{
        cout << "Enter at what day you started a call (Mo, Tu, We, Th, Fr, Sa, Su): ";
        cin >> day;
        while (day != "Mo" && day != "mo" && day != "Tu" && day != "tu" && day != "We" && day != "we" && day != "Th" && day != "th" && day != "Fr" && day != "fr" && day != "Sa" && day != "sa" && day != "Su" && day != "su" && day != "MO" && day != "TU" && day != "WE" && day != "TH" && day != "FR" && day != "SA" && day != "SU")
        {
            cout << "Invalid input. Please try: Mo, Tu, We, Th, Fr, Sa, and Su: ";
            cin >> day;
        }

        cout << "Enter at what time you started the call (HH:MM): ";
        cin >> hour >> colon >> minutes;
        while (cin.fail() || hour < 0 || hour > 23 || minutes < 0 || minutes > 59 || colon != ':') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "The time " << hour << colon << minutes << " is invalid. Please try again: ";
            cin >> hour >> colon >> minutes;
        }
        cout << "How long did your call last? (in minutes): ";
        cin >> duration;
        while (cin.fail() || duration < 0){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try a number not less than zero: ";
            cin >> duration;
        }
       
       double rate;

        if (day == "Su" || day == "Sa" || day == "su" || day == "sa" || day == "SU" || day == "SA" || day == "sU" || day == "sA") 
            {
            rate = 0.15;
        }     
        else {
                
            if (hour >= 8 && hour <= 16){
                rate = 0.40;
            }
            else if ((hour < 8 && hour >= 0) || (hour > 16 && hour <= 23)){
                rate = 0.25;
            }
        }
    

        totalcost = rate * duration;

        cout << "The cost of your call is $: " << totalcost;

        cout << "\n";
        cout << "Would you like to try again? (Yes or No): ";
        cin >> repeat;
        while (repeat != "Yes" && repeat != "yes" && repeat != "YES" && repeat != "No" && repeat != "no" && repeat != "NO")
        {
            cout << "Invalid input. Please try Yes or No: ";
            cin >> repeat;
        }
    } while (repeat == "Yes" ||repeat == "yes" || repeat == "YES");

    return 0;

}
