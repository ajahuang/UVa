#include <iostream>
#include <vector>
#include <cstring>
#include <limits>
#include <algorithm>
using namespace std;

struct Turtle
{
    int w, s;
};

bool comp(const Turtle &t1, const Turtle &t2)
{
   return t1.s < t2.s;
}

vector<Turtle> T;
int dp[5607];

void solve()
{
    sort(T.begin(), T.end(), comp);

    fill(dp, dp + 5607, numeric_limits<int>::max());
    dp[0] = 0;
    
    int maxNTurtles = 0;

    for (int i = 0; i < T.size(); ++i)
        for (int j = maxNTurtles; j >= 0; --j)
            // Try to put turtle i below the current stack of j turtles.
            // 1.Turtle i can carry the stack plus itself.
            // 2.They produce a smaller weight for the current stack of j+1 turtles.
            if (T[i].s >= dp[j] + T[i].w
                && T[i].w + dp[j] < dp[j + 1])
            {
                dp[j + 1] = dp[j] + T[i].w;
                maxNTurtles = max(maxNTurtles, j + 1);
            }
    
    cout << maxNTurtles << endl;
}

int main()
{
    Turtle t;
    while (cin >> t.w >> t.s)
        T.push_back(t);

    solve();
}