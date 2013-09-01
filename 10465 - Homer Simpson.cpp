#include <iostream>
#include <cstring>
using namespace std;

static const int ARRAY_SIZE = 18432;

/** memo[i] stores the maximum number of burgers Homer can eat 
    without having beer. */
int memo[ARRAY_SIZE];

int main()
{   
    int m, n, t;
    while (cin >> m >> n >> t)
    {
        memset(memo, -1, sizeof memo);
        memo[0] = 0;
        for (int i = 1; i <= t; ++i)
        {
            // Each number i can be reached by eating a burger for
            // m or n seconds.
            int burger1 = (i - m >= 0? memo[i - m] : -1);
            if (burger1 >= 0)
                ++burger1;

            int burger2 = (i - n >= 0? memo[i - n] : -1);
            if (burger2 >= 0)
                ++burger2;
            
            memo[i] = max(burger1, burger2);
        }
        if (memo[t] != -1)
            cout << memo[t] << endl;
        else
        {
            // Search the number of burgers closest to t.
            int i = t;
            while (memo[--i] == -1)
            {}
            cout << memo[i] 
                 << " " 
                 << t - i // The time Homer gets for drinking. 
                 << endl;
        }
    }
    return 0;
}