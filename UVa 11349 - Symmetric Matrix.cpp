#include <iostream>
#include <vector>
using namespace std;

// Return true if M is symmetric; false, otherwise.
// n can be even or odd.
template <typename T>
bool symmetric(const vector<vector<T> > &M)
{
    size_t n = M.size();

    for (size_t r = 0; r < (n + 1) / 2; ++r)
        for (size_t c = 0; c < (r == n / 2? (n + 1) / 2 : n); ++c)
        {
            if (M[r][c] < 0 
                || M[r][c] != M[n - 1 - r][n - 1 - c])
            {
                return false;
            }
        }
    return true;
}

int main()
{  
    size_t T, Test = 1;
    cin >> T;
    while ( T-- )
    {
        char c;
        size_t n;
        cin >> c >> c >> n;
        vector<vector<long long> > M(n, vector<long long>(n));
        for (int r = 0; r < n; ++r)
            for (int c = 0; c < n; ++c)
                cin >> M[r][c];
        
        cout << "Test #" << Test++ << ": ";
        if (symmetric(M))
            cout << "Symmetric." << endl;
        else
            cout << "Non-symmetric." << endl;        
    }
    return 0;
}