#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

bool comp(const string &s1, const string &s2)
{
    return s1.length() < s2.length();
}

int main()
{  
    size_t N;
    while (cin >> N)
    {
        vector<string> filenames(N);
        for (size_t i = 0; i < N; ++i)
            cin >> filenames[i];

        sort(filenames.begin(), filenames.end());
        size_t L = max_element(filenames.begin(), filenames.end(), comp)->length();
        // According to the problem description: (C - 1) * (L + 2) + L <= 60
        size_t C = (60 - L) / (L + 2) + 1; 
        // Round N / C up.
        size_t R = (N + C - 1) / C;
    
        cout << "------------------------------------------------------------" << endl;
        for (size_t i = 0; i < R; ++i)
        {
            // "all other columns will be the width of the longest filename plus 2" and
            // filenames are "formatted into left-justified columns."
            for (size_t j = i; j < N; j += R)
                cout << setw(L + 2) << setiosflags(ios::left) << filenames[j];
            
            cout << endl;
        }
    }
    return 0;
}