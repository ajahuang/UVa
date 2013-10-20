#include <iostream>
#include <cmath>
using namespace std;

// 1 <= N <= 10000
int memo[10001];

int main()
{   
    // Initialize memo[]
    for (int i = 1; i <= 10000; ++i)
    {
        // If i is a square number, memo[i] = 1; Otherwise memo[i] = i;
        int squareRoot = static_cast<int>(sqrt((double)i));
        if (squareRoot * squareRoot == i)
            memo[i] = 1;
        else
            memo[i] = i;
    }
    for (int i = 2; i <= 10000; ++i)
    {
        if (memo[i] == 1)
            continue;
        // Check every square number smaller than i.
        for (int j = 1; j * j < i; ++j)
            memo[i] = min(memo[i], 1 + memo[i - j * j]);
    }

    int t;
    cin >> t;
    while ( t-- )
    {
        int N;
        cin >> N;
        cout << memo[N] << endl;
    }
    return 0;
}