#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

static const int MAX_N = 19;

typedef unsigned long long ull_t;
ull_t memo[MAX_N + 2][MAX_N + 2];
int n;

ull_t a(int i, int j)
{
    if (memo[i][j] != -1)
        return memo[i][j];

    if (i >= j)
    {
        ull_t v1 = 0, v2 = 0;
        for (int k = i + 1; k <= n; ++k)
            v1 = max(v1, a(k, 1) + a(k, j));
        for (int k = 1; k < j; ++k)
            v2 = max(v2, a(i, k) + a(n, k)); 
        return memo[i][j] = v1 + v2;
    }
    else
    {
        ull_t v = a(i, i) + a(i + 1, j);
        for (int k = i + 1; k < j; ++k)
            v = max(v, a(i, k) + a(k + 1, j));
        return memo[i][j] = v;
    }
}

int main()
{  
    int a_n1;
    while (cin >> n >> a_n1)
    {
        memset(memo, -1, sizeof memo);
        memo[n][1] = a_n1;
        cout << a(1, n) << endl;
    }
    return 0;
}