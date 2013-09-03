#include <iostream>
#include <cstring>
using namespace std;

static const int MAX_LENGTH = ((1 + 26) * 26) / 2;
int memo[27][27][MAX_LENGTH + 1];

int main()
{   
    memset(memo, 0, sizeof memo);
    memo[0][0][0] = 1;

    /**
        memo[i][l][s] stores the number of strings of length l 
        and value s, considering up to letter i. So,
            memo[i][l][s] = memo[i - 1][l][s] 
                          + memo[i - 1][l - 1][s - i]
    */
    for (int i = 1; i <= 26; ++i)
        for (int l = 0; l <= i; ++l)
            for (int s = 0; s <= MAX_LENGTH; ++s)
            {
                // Letter i is not selected.
                memo[i][l][s] = memo[i - 1][l][s];
                // Letter i is selected.
                if (l > 0 && s >= i)
                    memo[i][l][s] += memo[i - 1][l - 1][s - i];
            }

    int T = 1, L, S;
    while (cin >> L >> S, !(L == 0 && S == 0))
    {
         cout << "Case " 
              << T++ 
              << ": ";
         if (L > 26 || S > MAX_LENGTH)
             cout << "0" << endl;
         else
             cout << memo[26][L][S] << endl;
    }
    return 0;
}