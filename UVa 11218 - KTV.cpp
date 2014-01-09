#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int> > C(81, vector<int>(3));
int S[81];

int solve()
{
    int maximum = -1;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            for (int k = j + 1; k < n; ++k)
            {
                // Do the teams C[i], C[j] and C[k] include all 
                // 9 people?
                vector<bool> p(10, false);
                p[C[i][0]] = true;
                p[C[i][1]] = true;
                p[C[i][2]] = true;
                p[C[j][0]] = true;
                p[C[j][1]] = true;
                p[C[j][2]] = true;
                p[C[k][0]] = true;
                p[C[k][1]] = true;
                p[C[k][2]] = true;
                if (count(p.begin(), p.end(), true) == 9)
                    maximum = max(maximum, S[i] + S[j] + S[k]);
            }
    return maximum;
}

int main()
{   
    int Case = 1;
    while (cin >> n, n > 0)
    {
        for (int i = 0; i < n; ++i)
            cin >> C[i][0] >> C[i][1] >> C[i][2] >> S[i];

        cout << "Case " << Case++ << ": " << solve() << endl;
    }
    return 0;
}
