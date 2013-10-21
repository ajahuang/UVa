#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{  
    int L;
    while (cin >> L, L != 0)
    {
        string S;
        cin >> S;

        int minDistance = L;
        int lastR = -L, lastD = -L;
        // Linearly scan the highway.
        for (int i = 0; i < L; ++i)
        {
            // Restaurant and drugstore.
            if (S[i] == 'Z')
            {
                minDistance = 0;
                break;
            }
            // Restaurant.
            else if (S[i] == 'R')
            {
                minDistance = min(minDistance, i - lastD);
                lastR = i;
            }
            // Drugstore.
            else if (S[i] == 'D')
            {
                minDistance = min(minDistance, i - lastR);
                lastD = i;
            }
        }
        cout << minDistance << endl;
    }
    return 0;
}