#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    while ( N-- )
    {
        int m, k;
        cin >> m >> k; // m books, k scribes.
        
        vector<long long> p(m);
        for (int i = 0; i < m; ++i)
            cin >> p[i];
                
        vector<int> finalDivision;
        long long U = accumulate(p.begin(), p.end(), 0LL);
        long long L = *max_element(p.begin(), p.end());
        while (U > L)
        {
            long long M = (L + U) / 2;
            long long sum = 0, maxSum = 0;
            vector<int> division;
            for (int i = m - 1; i >= 0; --i)
            {
                // Switch to the next scribe?
                if (sum + p[i] > M // This scribe is overloaded.
                    || i + 1 < k - division.size()) // Leave at least one book for other scribes.
                {
                    division.push_back(i);
                    sum = p[i];
                }
                else
                    sum += p[i];
                
                maxSum = max(maxSum, sum);
            }

            if (division.size() + 1 == k)
                finalDivision = division;

            // If no scribe's load is too heavy or there are too many devisions, increase L.
            if (maxSum > M || division.size() + 1 > k)
                L = M;
            else
                U = M;
            
            if ((L + U) / 2 == M)
                break;
        }
        
        for (int i = 0; i < m; ++i)
        {
            cout << (i > 0? " " : "") << p[i];
            if (!finalDivision.empty()
                && finalDivision.back() == i)
            {
                cout << " /";
                finalDivision.pop_back();
            }
        }
        cout << endl;
    }
}