#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int M, N;
int F[128];
int dp[1 << 11][1 << 11];

// Q: bitmask of questions.
// A: bitmask of answers.
int search(int Q, int A)
{
    if (dp[Q][A] != -1)
        return dp[Q][A];

    // If the number of remained objects are less than 2, then there is no
    // need to ask any other questions.
    int nObjects = 0;
    for (int i = 0; i < N; ++i)
        if ((F[i] & Q) == A)
            ++nObjects;

    if (nObjects <= 1)
        return dp[Q][A] = 0;

    // Try to ask each question and check its maximum number of required 
    // questions to identify the remained objects. Pick the minimum of them.
    int nQuestions = M + 1;
    for (int i = 0; i < M; ++i)
        if ((Q & (1 << i)) == 0)
            nQuestions = min(nQuestions, 1 + max(search(Q | (1 << i), A),
                                                 search(Q | (1 << i), A | (1 << i))));

    return dp[Q][A] = nQuestions;
}

int solve()
{
    memset(dp, -1, sizeof(dp));
    return search(0, 0);
}

int main()
{
    while (cin >> M >> N, !(M == 0 && N == 0))
    {
        for (int i = 0; i < N; ++i)
        {
            string s;
            cin >> s;
            
            int feature = 0;
            for (int j = 0; j < M; ++j)
                feature |= (s[j] - '0') << j;
            
            F[i] = feature;
        }
        cout << solve() << endl;
    }
    return 0;
} 