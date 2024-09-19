#include <iostream>
using namespace std;

int main() {

    double base, answer = base;
    int exponent;
    string repeat;

    do{
        cout << "Enter the base: ";
        cin >> base;
        cout << "Enter the exponent: ";
        cin >> exponent;

    
        if (exponent > 0) {
            answer = base;
        
            do{
                answer *= base;
                exponent -= 1;
            }

            while (exponent > 1);

        } else if (exponent == -1) {

            answer = 1/(base);

        } else if (exponent < -1){

            answer = 1/((exponent * -1) * (base));

        }
        
        else {
            answer = 1;
        }
        


        cout << "The result is: " << answer << endl;

        cout << "\nWould you like to try again? (Yes or No): ";
        cin >> repeat;
        while(repeat != "Yes" && repeat != "YES" && repeat != "yes" && repeat != "No" && repeat != "NO" && repeat != "no"){
            cout << "Invalid input. Please enter Yes or No: ";
            cin >> repeat;
        }
    
    } while (repeat == "Yes" || repeat == "YES" || repeat == "yes");

    return 0;
}