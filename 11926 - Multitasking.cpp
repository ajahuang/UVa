#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

bitset<1000001> schedule;

bool hasConflict(int n, int m, vector<int> &s, vector<int> &e, vector<int> &r)
{
    // One-time tasks.
    for (int i = 0; i < n; ++i)
    {
        int start = s[i], end = e[i];
        // "Touching" is OK, so check from start + 1.
        for (int t = start + 1; t <= end; ++t)
        {
            if (schedule.test(t))
                return true;
            else
                schedule.set(t);
        }
    }
    // Repeating tasks.
    for (int i = n; i < n + m; ++i)
    {
        int start = s[i], end = e[i], interval = r[i];     
        while (start < 1000000)
        {
            for (int t = start + 1; t <= end; ++t)
            {
                if (schedule.test(t))
                    return true;
                else
                    schedule.set(t);
            }          
            start += interval;
            end = min(end + interval, 1000000);
        }
    }
    return false;
}

int main()
{  
    int n, m;
    while (cin >> n >> m, !(n == 0 && m == 0))
    {
        vector<int> s(n + m), e(n + m), r(n + m);
        for (int i = 0; i < n; ++i)
            cin >> s[i] >> e[i];
        for (int i = n; i < n + m; ++i)
            cin >> s[i] >> e[i] >> r[i];

        schedule.reset();     
        if (hasConflict(n, m, s, e, r))
            cout << "CONFLICT" << endl;
        else
            cout << "NO CONFLICT" << endl;
    }
    return 0;
}