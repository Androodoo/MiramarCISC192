#include <iostream>
#include <iomanip>
using namespace std;

// THE AVERAGE TRAP

int main()
{
    int examScore1;
    int examScore2;
    int examScore3;

    cout <<"Input your exam scores 1, 2 ,3: ";
    cin >> examScore1 >> examScore2 >> examScore3;

    int rawAverage = (examScore1 + examScore2 + examScore3) / 3;
    double correctAverage = static_cast<double>(examScore1 + examScore2 + examScore3) / 3;

    cout <<"Raw Average (Implicit): " << rawAverage << endl;
    cout << fixed << setprecision(1) <<"Correct Average (Explicit cast): " << correctAverage << endl;

    return 0;
}