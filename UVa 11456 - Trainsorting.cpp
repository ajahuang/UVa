#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
using namespace std;

// Return the maximum length of LIS/LDS ending at S's last element.  
template <typename T>
size_t LIDS(const vector<size_t> &S, T comp)
{
    vector<size_t> L(S.size());
    size_t lisCount = 0, length = 0;
    for (size_t i = 0; i < S.size(); ++i)
    {
        size_t pos = lower_bound(L.begin(), L.begin() + lisCount, S[i], comp)
                     - L.begin();
        L[pos] = S[i];
        length = pos + 1;
        if (pos == lisCount)
            ++lisCount;
    }
    return length;
}

int main()
{  
    size_t T;
    cin >> T;
    while ( T-- )
    {
        size_t n;
        cin >> n;
        vector<size_t> cars(n);
        for (size_t i = 0; i < n; ++i)
            cin >> cars[i];
        
        size_t longestTrain = 0;
        vector<size_t>::iterator iter(cars.begin());
        for (; iter != cars.end(); ++iter)
        {
            // Pass in the vector(cars.end() .. iter). 
            size_t lis = LIDS(vector<size_t>(reverse_iterator<vector<size_t>::iterator>(cars.end()), 
                                             reverse_iterator<vector<size_t>::iterator>(iter)), 
                              less<size_t>());
            size_t lds = LIDS(vector<size_t>(reverse_iterator<vector<size_t>::iterator>(cars.end()), 
                                             reverse_iterator<vector<size_t>::iterator>(iter)), 
                              greater<size_t>());
            longestTrain = max(longestTrain, lis + lds - 1);
        }
        cout << longestTrain << endl;
    }
    return 0;
}