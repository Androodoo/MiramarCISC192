#include <iostream>
using namespace std;

// EXPRESSIONS & ASSIGNMENTS

int main()
{
    int a;
    int b;
    int c;

    cout <<"Please input a, b, c: ";

    cin >> a >> b >> c;

    cout <<"\na + b * c = " << a + b * c << endl;
    cout <<"(a + b) * c = " << (a + b) * c << endl;
    cout <<"a / b * c = " << a / b * c << endl;
    cout <<"a / (b * c) = " << a / (b * c) << endl;

    return 0;
}