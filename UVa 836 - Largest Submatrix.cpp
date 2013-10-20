#include <iostream>
#include <vector>
#include <string>
using namespace std;

static const int MINUS_INF = -(25 * 25);

int main()
{  
    size_t N;
    string s;

    cin >> N;
    cin.ignore();
    getline(cin, s);
    
    while ( N-- )
    {
        vector<vector<int> > M; // Cumulative sum matrix.
        size_t r = 0;
        while (getline(cin, s) && s != "")
        {
            M.push_back(vector<int>());
            for (size_t c = 0; c < s.size(); ++c)
            {
                // To include any '0' element will make a submatrix 
                // infeasible.
                M[r].push_back(s[c] == '0'? MINUS_INF : 1);
                if (r > 0)
                    M[r][c] += M[r - 1][c];
                if (c > 0)
                    M[r][c] += M[r][c - 1];
                if (r > 0 && c > 0)
                    M[r][c] -= M[r - 1][c - 1];
            }
            ++r;
        }
      
        int maxSubRect = 0;
        //   (sr,sc)
        //          x x x 
        //          x x x 
        //          x x x 
        //               (er, ec)
        for (size_t sr = 0; sr < M.size(); ++sr)
            for (size_t sc = 0; sc < M.size(); ++sc)
                for (size_t er = sr; er < M.size(); ++er)
                    for (size_t ec = sc; ec < M.size(); ++ec)
                    {
                        int subRect = M[er][ec];
                        if (sr > 0)
                            subRect -= M[sr - 1][ec];
                        if (sc > 0)
                            subRect -= M[er][sc - 1];
                        if (sr > 0 && sc > 0)
                            subRect += M[sr - 1][sc - 1];
                        maxSubRect = max(maxSubRect, subRect);
                    }

        cout << maxSubRect << endl;
        if (N)
            cout << endl;
    }
    return 0;
}