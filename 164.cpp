#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <algorithm>
#include <functional>
#include <cmath>
#include <bitset>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <cassert>
using namespace std;

#define CHANGE      0
#define INSERT      1
#define DELETE      2
#define EQUAL       4

string s, t;
int memo[21][21];
int trace[21][21];
int adjustLen;

void printResult(int i, int j)
{
    if (i == 0 && j == 0)
        return;

    if (trace[i][j] == EQUAL)
    {
        printResult(i - 1, j - 1);
        return;
    }
    else if (trace[i][j] == CHANGE)
    { 
        printResult(i - 1, j - 1);
        cout << "C" << t[j];
    }
    else if (trace[i][j] == DELETE)
    {   
        printResult(i - 1, j);
        --adjustLen;
        cout << "D" << s[i];
    }
    else if (trace[i][j] == INSERT)
    {
        printResult(i, j - 1);
        ++adjustLen;
        cout << "I" << t[j];
    }
    
    if (trace[i][j] == DELETE)
        ++i;
    if (i + adjustLen < 10)
        cout << "0";
    cout << i + adjustLen;
}

int main()
{
    while (cin >> s, s != "#")
    {
        cin >> t;
        s.insert(0, " ");
        t.insert(0, " ");

        for (int i = 0; i <= 20; ++i)
        {
            memo[0][i] = memo[i][0] = i;
            trace[0][i] = INSERT;
            trace[i][0] = DELETE;
        }

        for (int i = 1; i < s.size(); ++i)
            for (int j = 1; j < t.size(); ++j)
            {
                if (s[i] == t[j])
                {
                    memo[i][j] = memo[i - 1][j - 1];
                    trace[i][j] = EQUAL;
                    continue;
                }

                int cost[3];
                cost[CHANGE] = 1 + memo[i - 1][j - 1];
                cost[INSERT] = 1 + memo[i][j - 1];
                cost[DELETE] = 1 + memo[i - 1][j];
          
                // Select the action of smallest cost among CHANGE, INSERT and DELETE.
                int minCost = cost[CHANGE];
                memo[i][j] = cost[CHANGE];
                trace[i][j] = CHANGE;
                for (int act = INSERT; act <= DELETE; ++act)
                {
                    if (cost[act] < minCost)
                    {
                        minCost = cost[act];
                        memo[i][j] = cost[act];
                        trace[i][j] = act;
                    }
                }
            }

        adjustLen = 0;
        printResult(s.size() - 1, t.size() - 1);
        cout << "E" << endl;
    }
    return 0;
}
