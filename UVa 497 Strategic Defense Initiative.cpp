#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{  
    size_t T;
    cin >> T;
    cin.ignore();
    cin.ignore();
    while ( T-- )
    {
        vector<int> M;
        string s;
        while (getline(cin, s) && s != "")
        { 
            stringstream ss(s);
            int missle;

            ss >> missle;
            M.push_back(missle);
        }

        // O(n^2) DP.
        vector<int> LIS(M.size(), 1);
        vector<int> path(M.size(), -1);
        LIS[0] = 1;      
        for (size_t i = 1; i < M.size(); ++i)
            for (size_t j = 0; j < i; ++j)
            {
                int l = M[j] < M[i]? LIS[j] + 1 : 0;
                if (l > LIS[i])
                {
                    LIS[i] = l;
                    path[i] = static_cast<int>(j);
                }
            }
        // Print the path.
        int i = static_cast<int>(distance(LIS.begin(),
                                          max_element(LIS.begin(), LIS.end()) 
                                          )
                                 );
        vector<int> print(1, M[i]);
        while (path[i] != -1)
        {
            i = path[i];
            print.insert(print.begin(), M[i]);
        }
        cout << "Max hits: " << print.size() << endl;
        copy(print.begin(), print.end(), ostream_iterator<int>(cout, "\n"));
        if (T)
            cout << endl;
    }
    return 0;
}