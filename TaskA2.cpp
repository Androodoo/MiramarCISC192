#include <iostream>
#include <iomanip>
using namespace std;

// COMPOUND ASSIGNMENT

int main()
{
    double balance;
    int depositsCount;
    int withdrawalsCount;

    double depositsValue = 25.50;
    double withdrawalsValue = 12.75;



    cout <<"Please input your balance, deposits, withdrawals: ";
    cin >> balance >> depositsCount >> withdrawalsCount;
    cout <<fixed <<setprecision(2) <<"\nBalance: $" << balance << endl;
    cout << "Deposits: " << depositsCount << "\nWithdrawals: " << withdrawalsCount << endl;



    double finalBalance = balance + (depositsCount * depositsValue) - (withdrawalsCount * withdrawalsValue);


    cout << fixed << setprecision(2) << "\nYour final balance is: $" << finalBalance << endl;

    return 0;
}