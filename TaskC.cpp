#include <iostream>
#include <iomanip>
using namespace std;

// PAYCHECK CALCULATOR

int main()
{
    
    double hours;
    double rate;
    double otHours = 0.00;
    double benefitsFee = 35.00;
    double taxRate = 0.18;

    cout << "Input: ";
    cin >> hours >> rate;

    if (hours > 40){
        otHours = hours - 40;
    }

    double gross = ((hours - otHours) * rate) + (otHours * rate * 1.5);
    double tax = gross * taxRate;
    double net = gross - tax - benefitsFee;

    cout << fixed << setprecision(2) << "\nRegular: " << hours - otHours << " hours, " <<  "Overtime: " << otHours << " hours" << endl;
    cout << fixed << setprecision(2) << "Gross: $" << gross << endl;
    cout << fixed << setprecision(2) << "Tax (18%): $" << tax << endl;
    cout << fixed << setprecision(2) << "Benefits: $" << benefitsFee << endl;
    cout << fixed << setprecision(2) << "Net: $" << net << endl;
    
}