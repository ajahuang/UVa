#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{  
    size_t Case = 1;
    size_t N, Q;
    while (cin >> N >> Q, !(N == 0 && Q == 0))
    {
        vector<int> marbles(N);
        for (size_t i = 0; i < N; ++i)
            cin >> marbles[i];

        sort(marbles.begin(), marbles.end());
        cout << "CASE# " << Case++ << ":" << endl;
        for (size_t i = 0; i < Q; ++i)
        {
            int query;
            cin >> query;
            pair<vector<int>::iterator, vector<int>::iterator> range;
            range = equal_range(marbles.begin(), marbles.end(), query);
            if (range.first == marbles.end() 
                || *range.first != query)
            {
                cout << query << " not found" << endl;
            }
            else
                cout << query 
                     << " found at " 
                     << distance(marbles.begin(), range.first) + 1
                     << endl;
        }
    }
    return 0;
}