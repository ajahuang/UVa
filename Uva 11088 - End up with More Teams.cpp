#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
vector<int> C;
int memo[1 << 20];

int search(int bitMask)
{
    if (bitMask == (1 << N) - 1)
        return 0;

    if (memo[bitMask] != -1)
        return memo[bitMask];

    int pTeams = 0;
    for (int i = 0; i < N; ++i)
        if ((bitMask & (1 << i)) == 0)
            for (int j = i + 1; j < N; ++j)
                if ((bitMask & (1 << j)) == 0)
                    for (int k = j + 1; k < N; ++k)
                        if ((bitMask & (1 << k)) == 0)
                            pTeams = max(pTeams, (C[i] + C[j] + C[k] >= 20? 1 : 0)
                                                 + search(bitMask | (1 << i) | (1 << j) | (1 << k)));                     

    return memo[bitMask] = pTeams;
}

int solve()
{
    memset(memo, -1, sizeof (memo));
    return search(0);
}

int main()
{   
    int Case = 1;
    while (cin >> N, N > 0)
    {
        C.resize(N);
        for (int i = 0; i < N; ++i)
            cin >> C[i];

        cout << "Case " << Case++ << ": " << solve() << endl;
    }
    return 0;
}
