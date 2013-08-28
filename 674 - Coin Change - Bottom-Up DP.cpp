#include <iostream>
using namespace std;

int coins[] = {50, 25, 10, 5, 1};
int ways[8192];

int main()
{   
    // The problem description says "we count that there is one way 
    // of making change for zero cent".
    ways[0] = 1;

    // Every j cent (j = 0 to 8191) can be reached by taking off one
    // of the coins, so just sum up their ways.
    for (int i = 0; i < 5; ++i)
        for (int j = coins[i]; j < 8192; ++j)
            ways[j] += ways[j - coins[i]];

    int money;
    while (cin >> money)
    {
        cout << ways[money] << endl;        
    }
    return 0;
}