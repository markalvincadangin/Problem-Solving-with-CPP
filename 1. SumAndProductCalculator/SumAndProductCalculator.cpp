#include <iostream>

using namespace std;

int main() {

    int numOne, numTwo;
    int resultSum, resultProduct;

    
    cout << "Enter the first number: ";
    cin >> numOne;

    cout << "Enter the second number: ";
    cin >> numTwo;

    resultSum = numOne + numTwo;
    resultProduct = numOne * numTwo;


    cout << "The sum is: " << resultSum << endl; 
    cout << "The product is: " << resultProduct << endl;

    return 0;
}