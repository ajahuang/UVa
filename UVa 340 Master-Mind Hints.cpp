#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{  
    int Game = 1;
    int N;
    while (cin >> N, N > 0)
    {
        vector<int> code(N);
        for (int d = 0; d < N; ++d)
            cin >> code[d];
        
        cout << "Game " << Game++ << ":" << endl;
        while (N == N)
        {
            vector<int> guess(N);
            for (int i = 0; i < N; ++i)
                cin >> guess[i];

            if (count(guess.begin(), guess.end(), 0) == N)
                break;

            int i = 0, j = 0;
            vector<bool> marks(N, false);
            // Check strong matches.
            for (int d = 0; d < N; ++d)
                if (code[d] == guess[d])
                {
                    ++i;
                    marks[d] = true;
                    guess[d] = -1;
                }
            // Check weak matches.
            for (int d = 0; d < N; ++d)
                if (! marks[d]) 
                {
                    vector<int>::iterator iter = 
                        find(guess.begin(), guess.end(), code[d]);
                    if (iter != guess.end())
                    {
                        ++j;
                        marks[d] = true;
                        *iter = -1;
                    }
                }
            cout << "    ("
                 << i
                 << ","
                 << j
                 << ")"
                 << endl;
        }
    }
    return 0;
}