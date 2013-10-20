#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{  
    int m;
    cin >> m;
    cin.ignore();
    while ( m-- )
    {
        string s;
        getline(cin, s);
        stringstream ss(s);

        vector<int> sums(1, 0);
        int sum = 0;
        int k;
        while (ss >> k)
        {
            sum += k;
            size_t size = sums.size();
            // Consider all possible sums.
            for (size_t i = 0; i < size; ++i)
                sums.push_back(sums[i] + k);
        }
        if (sum % 2 == 0 
            && find(sums.begin(), sums.end(), sum / 2) != sums.end())
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}