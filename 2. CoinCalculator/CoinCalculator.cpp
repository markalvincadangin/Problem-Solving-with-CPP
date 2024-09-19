#include <iostream>

using namespace std;

int main() {

    double dimes, quarters, nickels, totalCents, totalDollars;

    cout << "Enter how many dimes you have: ";
    cin >> dimes;
    cout << "Enter how many quarters you have: ";
    cin >> quarters;
    cout << "Enter how many nickels you have: ";
    cin >> nickels;

    totalCents = (dimes * 10) + (quarters * 25) + (nickels * 5);
    totalDollars = totalCents / 100;

    cout << "You're coins are worth " << static_cast<int>(totalCents) << " cents or $ " << totalDollars << endl;

    return 0;
}

