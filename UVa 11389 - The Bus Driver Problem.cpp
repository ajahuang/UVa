#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{  
    int n, d, r;
    while (cin >> n >> d >> r, !(n == 0 && d == 0 && r == 0))
    {
        vector<int> mRoute(n);
        vector<int> eRoute(n);

        for (int i = 0; i < n; ++i)
            cin >> mRoute[i];
        for (int i = 0; i < n; ++i)
            cin >> eRoute[i];

        // Make each driver work as long as possible.
        sort(mRoute.begin(), mRoute.end());
        sort(eRoute.rbegin(), eRoute.rend());

        int overTimePay = 0;
        for (int i = 0; i < n; ++i)
        {
            int totalHours = mRoute[i] + eRoute[i];
            overTimePay += totalHours > d?
                           (totalHours - d) * r : 0;
        }
        cout << overTimePay << endl;
    }
    return 0;
}