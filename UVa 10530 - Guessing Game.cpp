#include <iostream>
#include <string>
using namespace std;

int main()
{  
    // Lower bound and upper bound.
    int L = 1, U = 10;
    int guess;
    while (cin >> guess, guess != 0)
    {
        string response;
        cin.ignore();
        getline(cin, response);
        if (response == "too high")
            U = min(U, guess - 1);
        else if (response == "too low")
            L = max(L, guess + 1);
        else if (response == "right on")
        {
            if (guess <= U && guess >= L)
                cout << "Stan may be honest" << endl;
            else
                cout << "Stan is dishonest" << endl;
            L = 1;
            U = 10;
        }
    }
    return 0;
}