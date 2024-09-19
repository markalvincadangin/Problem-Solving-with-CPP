//File Name: PayrollCalculator.cpp
//Author: Mark Alvin Cadangin
//Email Address: markalvin.cadangin@wvsu.edu.ph
//Assignment Number: 
//Description: A program that calculates the net pay of an employee based on the number of hours worked and the number of dependents.
//Last Changed: September 17, 2024

#include <iostream>
#include <limits>

using namespace std;

int main(){

    double rate = 16.78, overtimeRate, hoursWorked, grossPay, socialSecurityTax, federalIncomeTax, stateIncomeTax, unionDues = 10.0, extraHealthInsurance = 35.0, netPay;
    int dependents;
    string response;

    do{
        cout << "Enter the number of hours worked: ";
        cin >> hoursWorked;
        while (cin.fail() || hoursWorked < 0){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive number: ";
            cin >> hoursWorked;
        }

        cout << "Enter the number of dependents: ";
        cin >> dependents;
        while (cin.fail() || dependents < 0){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive number: ";
            cin >> dependents;
        }


        if (hoursWorked <= 40){
            grossPay = rate * hoursWorked;
            socialSecurityTax = grossPay * 0.06;
            federalIncomeTax = grossPay * 0.14;
            stateIncomeTax = grossPay * 0.05;
            if (dependents >= 3){
                netPay = grossPay - socialSecurityTax - federalIncomeTax - stateIncomeTax - unionDues - extraHealthInsurance;
            } else {
                netPay = grossPay - socialSecurityTax - federalIncomeTax - stateIncomeTax - unionDues;
            }
            
        } else {
            overtimeRate = rate * 1.5;
            grossPay = (rate * 40) + (overtimeRate * (hoursWorked - 40));
            socialSecurityTax = grossPay * 0.06;
            federalIncomeTax = grossPay * 0.14;
            stateIncomeTax = grossPay * 0.05;
            if (dependents >= 3){
                netPay = grossPay - socialSecurityTax - federalIncomeTax - stateIncomeTax - unionDues - extraHealthInsurance;
            } else {
                netPay = grossPay - socialSecurityTax - federalIncomeTax - stateIncomeTax - unionDues;
            }  
        }

        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);

        cout <<endl;
        cout << "Gross Pay: $" << grossPay << endl;
        cout << "Social Security Tax: $" << socialSecurityTax << endl;
        cout << "Federal Income Tax: $" << federalIncomeTax << endl;
        cout << "State Income Tax: $" << stateIncomeTax << endl;
        cout << "Union Dues: $" << unionDues << endl;
        
        if (dependents >= 3){
            cout << "Extra Health Insurance: $" << extraHealthInsurance << endl;
        }

        cout << "Net Pay: $" << netPay << endl << endl;

        cout << "Would you like to try again? (Yes or No): ";
        cin >> response;
        while (response != "yes" && response != "Yes" && response != "YES" && response != "no" && response != "No" && response != "NO"){
            cout << "Invalid input. Please enter 'Yes' or 'No': ";
            cin >> response;
        }
    } while (response == "yes" || response == "Yes" || response == "YES");

}