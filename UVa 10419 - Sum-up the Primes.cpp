#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int N, t;
vector<int> primes;
bool dp[150][1000+5][14];
int path[14];

bool comp(int a, int b)
{
    stringstream ss1;
    stringstream ss2;
    ss1 << a;
    ss2 << b;
    return ss1.str() < ss2.str();
}

// idx: index of "primes".
// sum: the current sum.
//   r: the number of chosen primes.
bool search(int idx, int sum, int r)
{
    if (idx == primes.size())
        return false;
    
    if (r == t)
    {
        if (sum == N)
            return true;
        return false;
    }
    
    if (sum >= N)
        return false;
    
    if (!dp[idx][sum][r])
        return false;
    
    path[r] = primes[idx];
    if (search(idx + 1, sum + primes[idx], r + 1))
        return true;
    if (search(idx + 1, sum, r))
        return true;

    return dp[idx][sum][r] = false;
}

void solve()
{
    memset(dp, true, sizeof(dp));
    if (search(0, 0, 0))
    {
        cout << path[0];
        for (int i = 1; i < t; ++i)
            cout << "+" << path[i];
        cout << endl;
    }
    else
        cout << "No Solution." << endl;
}

int main()
{
    bool isPrime[300];
    memset(isPrime, true, sizeof(isPrime));

    for (int i = 2; i * i < 300; ++i)
        if (isPrime[i])
            for (int j = i + i; j < 300; j += i)
                isPrime[j] = false;

    primes.push_back(2);
    for (int i = 3; i < 300; ++i)
        if (isPrime[i])
        {
            primes.push_back(i);
            primes.push_back(i);
        }
    
    sort(primes.begin(), primes.end(), comp);
    
    int Case = 1;
    while (cin >> N >> t, !(N == 0 && t == 0))
    {
        cout << "CASE " << Case++ << ":" << endl;
        solve();
    }
}