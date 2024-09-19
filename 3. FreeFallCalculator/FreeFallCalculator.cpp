#include <iostream>

using namespace std;

int main() {

    const double acceleration = 32.0;
    double time, distance;

    cout << "Enter the time in seconds: ";
    cin >> time;

    distance = (acceleration * (time * time)) / 2.0;

    cout << "An object would drop " << distance << " feet if it is in freefall for the time of " << time << " seconds." << endl;

    return 0;

}