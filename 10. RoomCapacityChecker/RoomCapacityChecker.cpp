//File Name: RoomCapacityChecker.cpp
//Author: Mark Alvin Cadangin
//Email Address: markalvin.cadangin@wvsu.edu.ph
//Assignment Number: 
//Description: A program that checks if the number of people in a room is legal based on the maximum capacity of the room.
//Last Changed: September 17, 2024


#include <iostream>
#include <limits>
using namespace std;

int main(){

    int maxCapacity, currentCapacity, newCapacity;
    string response;
    
    do{
        cout << "Enter the maximum capacity of the room: ";
        cin >> maxCapacity;
        while (cin.fail() || maxCapacity < 0){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive number: ";
            cin >> maxCapacity;
        }

        cout << "Enter the current number of people in the room: ";
        cin >> currentCapacity;
        while (cin.fail() || currentCapacity < 0){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive number: ";
            cin >> currentCapacity;
        }

        if (currentCapacity <= maxCapacity){
            cout << "It is legal to have " << currentCapacity << " people in the room." << endl;
            newCapacity = maxCapacity - currentCapacity;
            cout << newCapacity << " more people can enter the room." << endl;
        } else {
            cout << "It is illegal to have " << currentCapacity << " people in the room." << endl;
            newCapacity = currentCapacity - maxCapacity;
            cout << newCapacity << " people must leave the room." << endl;
            }

        cout << "Would you like to try again? (Yes or No): ";
        cin >> response;
        while (response != "yes" && response != "Yes" && response != "YES" && response != "no" && response != "No" && response != "NO"){
            cout << "Invalid input. Please enter 'Yes' or 'No': ";
            cin >> response;
        }
    } while (response == "yes" || response == "Yes" || response == "YES");
}