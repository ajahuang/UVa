#include <iostream>
#include <vector>
#include <cstdlib>
#include <numeric>
using namespace std;

const int TRIALS = 1000000;

int N;
vector<int> numbers;

void solve()
{
    for (int trial = 1; trial <= TRIALS; ++trial)
    {    
        vector<int> S;
        vector<bool> used(2 * N - 1, false);
        for (int i = 1; i <= N; ++i)
        {  
            int select = rand() % (2 * N - 1);
            if (used[select])
            {
                --i;
                continue;
            }
            used[select] = true;
            S.push_back(numbers[select]);
        }
        if (accumulate(S.begin(), S.end(), 0) % N == 0)
        {
            cout << "Yes" << endl;
            cout << S[0];
            for (int i = 1; i < S.size(); ++i)
                cout << " " << S[i];
            cout << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int main()
{
    while (cin >> N, N > 0)
    {
        numbers.clear();
        for (int i = 0; i < 2 * N - 1; ++i)
        {
            int n;
            cin >> n;
            numbers.push_back(n);
        }
        solve();
    }
}
