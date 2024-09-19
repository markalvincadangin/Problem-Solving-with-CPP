#include <iostream>
using namespace std;

int main() {

    double mphSpeed, minutes, seconds;
    string repeat;

    do{
        cout << "Enter the speed in mph: ";
        cin >> mphSpeed;

        minutes = 60 / mphSpeed;
        seconds = (minutes - static_cast<int>(minutes)) * 60;

        cout << "The speed is " << static_cast<int>(minutes) << " minutes and "; 
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(1);
        cout << seconds << " seconds per mile. " << endl;

        cout << "Do you want to repeat the program? (Yes or No): ";
        cin >> repeat;
        while(repeat != "yes" && repeat != "no" && repeat != "Yes" && repeat != "No" && repeat != "YES" && repeat != "NO"){
            cout << "Invalid input. Please enter Yes or No: ";
            cin >> repeat;
        }
    } while (repeat == "yes" || repeat == "Yes" || repeat == "YES");

    return 0;
}