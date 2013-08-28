#include <iostream>
#include <cstring>
using namespace std;

/** This solution uses Top-Down DP, but the problem can be solved more 
    efficiently by Bottom-Up DP. 
*/

int coins[] = {50, 25, 10, 5, 1};

/**
    memo[m][i] stores the number of different ways of making changes 
    for m cents using the coins of index >= i.
*/
int memo[8192][5];

int waysOfChanges(int money, int coinsIndex)
{
    if (money == 0)
        return 1;
    if (memo[money][coinsIndex] != -1)
        return memo[money][coinsIndex];

    int ways = 0;

    /** Consider the coins of index >= coinsIndex. This is to avoid
        repetitions in the search. For example, for money = 11, 5 5 1 
        and 1 5 5 should be counted as the same way.
    */
    for (int i = coinsIndex; i < 5; ++i)
    {
        if (money >= coins[i])
            ways += waysOfChanges(money - coins[i], i);
    }

    return memo[money][coinsIndex] = ways;
}

int main()
{    
    int money;

    // No need to reset memo for every input case.
    memset(memo, -1, sizeof memo);
    while (cin >> money)
    {
        cout << waysOfChanges(money, 0) << endl;
    }
    return 0;
}