#include <iostream>
#include <cstring>
#include <numeric>
using namespace std;

int M, sum, sticks[20];
int memo[1 << 20];

int search(int length, int bitMask)
{
    if (memo[bitMask] != -1)
        return memo[bitMask];

    if (length > sum / 4)
        return 0;
    else if (length == sum / 4)
    {
        if (bitMask == (1 << M) - 1)
            return 1;
        length = 0;
    }

    for (int i = 0; i < M; ++i)
        if ((bitMask & 1 << i) == 0
            && search(length + sticks[i], bitMask | 1 << i))
        {
            return 1;
        }
    return memo[bitMask] = 0;
}      

int solve()
{
    sum = accumulate(sticks, sticks + M, 0);
    if (sum % 4 != 0)
        return 0;

    memset(memo, -1, sizeof memo);
    return search(0, 0);
}

int main()
{   
    int N;
    cin >> N;
    while ( N-- )
    {
        cin >> M;
        for (int i = 0; i < M; ++i)
            cin >> sticks[i];

        cout << (solve()? "yes" : "no") << endl;
    }
    return 0;
}
