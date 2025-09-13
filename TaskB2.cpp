#include <iostream>
#include <iomanip>
using namespace std;

// PERCENTAGE WITH SAFE CASTING

int main()
{
    int wins, losses = 0;

    cout <<"Input your number of games and losses: ";
    cin >> wins >> losses;

    int totalGames = wins + losses;
    cout <<"\nWins: " << wins << "\nLosses: " << losses << "\nTotal Games: " << totalGames << endl;
    
    if(totalGames == 0){
        cout << "Win Rate: N/A - NO GAMES PLAYED." << endl;
    }
    else{
        double winRate = ((static_cast<double>(wins)) / (static_cast<double>(totalGames))) * 100.0;
        cout << fixed << setprecision(1) << "Win Rate: " << winRate << "%" << endl;
    }

    return 0;
}