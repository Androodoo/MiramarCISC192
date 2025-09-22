#include <iostream>
using namespace std;

// CALCULATOR

    /* 
    I will be using enum for
    add a
    subtract s
    multiply m
    divide d
    */

enum class Operation { Add = 'a', Subtract = 's', Multiply = 'm', Divide = 'd'};

int main()
{

double number{};
cout << "Enter a value ";
if(!(cin >> number)){
    cerr << "Not a valid number. " << endl;
    return 1;
}
double secondNumber{};
cout << number << " added, subtracted, multiplied, or divided by (input second number here): ";
if(!(cin >> secondNumber)){
    cerr << "Not a valid number. " << endl;
    return 1; //1 for invalid input
}

//Here we will read the operation that the user wants with the enum

cout << "select your operator (a), (s), (m), (d): ";
char mathOperator{};
cin >> mathOperator;
switch(static_cast<Operation>(mathOperator)){
    case Operation::Add:
        cout << number << " + " << secondNumber << " = " << (number + secondNumber);
            break;

    case Operation::Subtract:
        cout << number << " - " << secondNumber << " = " << (number - secondNumber);
            break;

    case Operation::Multiply:
        cout << number << " * " << secondNumber << " = " << (number * secondNumber);
            break;

    case Operation::Divide:
        if(secondNumber == 0){
            cerr << "Dividing by zero; Error." << endl;
            return 2; //2 for diving by 0 error
        }
        else{cout << number << " / " << secondNumber << " = " << (number / secondNumber);}
            break;
    default:
        cerr << "Not a valid operator; use 'a' to add, 's' to subtract, 'm' to multiply, or 'd' to divide.";
        return 1; //1 for invalid input
}

return 0; //0 for good :)
}