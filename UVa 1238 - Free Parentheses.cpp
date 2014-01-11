#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

const int SHIFT = 100;

vector<int> N;
vector<char> S; 
set<int> V;
bool dp[30 + 5][30 + 5][6000 + 5];

void search(int idx, int nLeftParen, int value)
{
    if (idx == N.size())
    {
        V.insert(value);
        return;
    }
    else if (dp[idx][nLeftParen][value + idx * SHIFT])
        return;

    // Put a left parenthesis.
    // It's necessary to use S[] for the case -0.
    if (S[idx] == '-')
        search(idx + 1, 
               nLeftParen + 1, 
               value + (nLeftParen % 2 == 0? N[idx] : -N[idx]));

    // Put 0, 1 .. up to nParen right parentheses.
    for (int i = 0; i <= nLeftParen; ++i)
        search(idx + 1, 
               nLeftParen - i, 
               value + (nLeftParen % 2 == 0? N[idx] : -N[idx])); 

    dp[idx][nLeftParen][value + idx * SHIFT] = true;
}

int solve()
{
    memset(dp, false, sizeof(dp));
    V.clear();
    search(0, 0, 0);
    return (int)V.size(); 
}

int main()
{
    string s;
    while (getline(cin, s)) 
    {
        stringstream ss(s);
        char sign;
        int num;

        ss >> num;
        N.clear();
        S.clear();
        N.push_back(num);
        S.push_back('+');
        while (ss >> sign >> num)
        {
            N.push_back(sign == '+'? num : -num);
            S.push_back(sign);
        }
        cout << solve() << endl;
    }
    return 0;
} 