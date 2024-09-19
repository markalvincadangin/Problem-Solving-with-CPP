//File Name: LoanCalculator.cpp
//Author: Mark Alvin Cadangin
//Email Address: markalvin.cadangin@wvsu.edu.ph
//Assignment Number: 
//Description: This program calculates the face value of a loan, the total interest paid, and the monthly payment of a loan.
//Last Changed: September 16, 2024

#include <iostream>
#include <limits>
using namespace std;

int main() {

    double consumerNeed, interestRate, durationYear, monthlyPayment, faceValue, interest;
    int durationMonth;
    string response;

    do{
        cout << "Enter the how much money you need ($): ";
        cin >> consumerNeed;
        while(cin.fail() || consumerNeed <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Inavlid input. Please enter a positive number: ";
            cin >> consumerNeed;
        }

        cout << "Enter the interest rate (%): ";
        cin >> interestRate;
        while(cin.fail() || interestRate <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Inavlid input. Please enter a positive number: ";
            cin >> interestRate;
        }

        cout << "Enter the duration of the loan (months): ";
        cin >> durationMonth;
        while(cin.fail() || durationMonth <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Inavlid input. Please enter a positive number: ";
            cin >> durationMonth;
        }

        durationYear = durationMonth / 12.0;
        faceValue = consumerNeed / (1 - (interestRate / 100) * durationYear);
        interest = faceValue - consumerNeed;
        monthlyPayment = faceValue / durationMonth;
        
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);

        cout << "The face value of the loan is: $" << faceValue << endl;
        cout << "The total interest paid is: $" << interest << endl;
        cout << "The monthly payment is: $" << monthlyPayment << endl;

        cout << "Would you like to calculate another loan? (Yes or No)): ";
        cin >> response;
        while(response != "Yes" && response != "No" && response != "yes" && response != "no" && response != "YES" && response != "NO") {
            cout << "Invalid input. Please enter Yes or No: ";
            cin >> response;
        }
    } while(response == "Yes" || response == "yes" || response == "YES");
    return 0;
}


