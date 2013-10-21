#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{  
    size_t round;
    while (cin >> round, round != -1)
    {
        string solution, guess;
        cin >> solution >> guess;

        int stroke = 0;
        for (size_t i = 0; i < guess.size() 
                           && stroke <= 6 
                           && solution != ""; ++i)
        {
            if (solution.find(guess[i]) != string::npos)
            {
                // Remove all guess[i] in solution.
                solution.erase(remove(solution.begin(), solution.end(),
                                      guess[i]),
                               solution.end());
            }
            else
                ++stroke;
        }
        cout << "Round " << round << endl;
        if (stroke == 7)
            cout << "You lose." << endl;
        else if (solution == "")
            cout << "You win." << endl;
        else
            cout << "You chickened out." << endl;
    }
    return 0;
}