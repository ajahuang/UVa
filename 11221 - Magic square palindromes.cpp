#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

bool isMSPalindrom(const string &s, size_t K)
{
    // s.size() must be a square number.
    if (K * K != s.size())
        return false;
    if (K == 1)
        return true;

    for (size_t add = 1; add <= K; add *= K)
    {
        string::const_iterator iter(s.begin());
        string::const_reverse_iterator r_iter(s.rbegin());
        for (size_t addCount = 0; addCount < K; ++addCount)
        {
            if (*iter != *r_iter)
                return false;
            iter += add;
            r_iter += add;
        }
    }
    return true;
}

bool isIgnoredChar(char c)
{
    if (c < 'a' || c > 'z')
        return true;
    return false;
}

int main()
{  
    string s;
    getline(cin, s);
    stringstream ss(s);
    size_t T;
    ss >> T;
    size_t Case = 1;
    while ( T-- )
    {
        getline(cin, s);
        // Remove all whitespace and punctuation symbols.
        s.erase(remove_if(s.begin(), s.end(), isIgnoredChar), s.end());
        size_t K = static_cast<size_t>(sqrt(static_cast<double>(s.size()) + 0e-9));
        cout << "Case #" << Case++ << ":" << endl;
        if (isMSPalindrom(s, K))
            cout << K << endl;
        else
            cout << "No magic :(" << endl;
    }
    return 0;
}