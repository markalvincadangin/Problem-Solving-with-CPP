//File Name: CarpetPriceCalculatorV2.cpp
//Author: Mark Alvin Cadangin
//Email Address: markalvin.cadangin@wvsu.edu.ph
//Assignment Number: 
//Description: This program calculates the total price of a carpet based on its length in meters. 
//             It prompts the user to enter the price per meter and the minimum length required to avail a discount. 
//             The program ensures that the price per meter is a positive value. If the length of the carpet exceeds 
//             the minimum length, a discount is applied to the total price.
//Last Changed: September 16, 2024

#include <iostream>
using namespace std;

int main() {

    double length, totalPrice, pricePerMeter, discount, minLenghtDiscount;
    string response;

    do{
        cout << "Enter the price per meter of the carpet: ";
        cin >> pricePerMeter;
        while(pricePerMeter <= 0){
            cout << "Invalid price. Please enter a valid price (in dollars): ";
            cin >> pricePerMeter;
        }

        cout << "Enter the minimum length to avail the discount: ";
        cin >> minLenghtDiscount;
        while(minLenghtDiscount <= 0){
            cout << "Invalid length. Please enter a valid length (in meters): ";
            cin >> minLenghtDiscount;
        }

        cout << "Enter the discount percentage (Enter 10 instead of 10%): ";
        cin >> discount;
        while(discount < 0 || discount > 100){
            cout << "Invalid discount. Please enter a valid discount percentage (0-100): ";
            cin >> discount;
        }

        cout << "Enter the length of the carpet in meters: ";
        cin >> length;
        while(length <= 0){
            cout << "Invalid length. Please enter a valid length (in meters): ";
            cin >> length;
        }

        if (length > minLenghtDiscount){
            totalPrice = pricePerMeter * length - ((length - minLenghtDiscount) * pricePerMeter * (discount/100));
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