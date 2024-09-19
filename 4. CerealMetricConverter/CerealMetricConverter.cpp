#include <iostream>
#include <limits>
using namespace std;

int main (){

    const double metricTon = 35273.92;
    double weightInOunces;
    int boxesNeeded;
    string response;

    do {
        cout << "Enter the weight of a package in ounces: ";
        cin >> weightInOunces;
        while (cin.fail() || (weightInOunces <= 0)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid weight. Please enter a positive number: ";
            cin >> weightInOunces;
        }

        double weightInTons = weightInOunces / metricTon;

        boxesNeeded = static_cast<int>(metricTon / weightInOunces);

        cout << "The weight of the package in metric tons is: " << weightInTons << endl;
        cout << "The number of boxes needed to yield one metric ton of cereal is: " << boxesNeeded << endl;

        cout << "Would you like to try again? (Yes or No): ";
        
        cin >> response;
        while (cin.fail() || (response != "Yes" && response != "yes" && response != "YES" &&  response != "No" && response != "no" && response != "NO")) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid response. Please enter Yes or No: ";
            cin >> response;
        }
    } while (response == "Yes" || response == "yes" || response == "YES");

    return 0;
}