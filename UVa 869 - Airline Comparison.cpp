#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static const int SIZE = 128;

int main()
{    
    int T;
    cin >> T;
    while ( T-- )
    {
        int N;
        cin >> N;

        vector<vector<int> > C1(SIZE, vector<int>(SIZE, 0));

        for (int i = 0; i < N; ++i)
        {
            char u, v;
            cin >> u >> v;
            C1[u][v] = 1;
        }

        int M;
        cin >> M;

        for (int k = 0; k < SIZE; ++k)
            for (int i = 0; i < SIZE; ++i)
                for (int j = 0; j < SIZE; ++j)
                    if (C1[i][k] && C1[k][j])
                        C1[i][j] = 1;
                
        vector<vector<int> > C2(SIZE, vector<int>(SIZE, 0));

        for (int i = 0; i < M; ++i)
        {
            char u, v;
            cin >> u >> v;
            C2[u][v] = 1;
        }

        for (int k = 0; k < SIZE; ++k)
            for (int i = 0; i < SIZE; ++i)
                for (int j = 0; j < SIZE; ++j)
                    if (C2[i][k] && C2[k][j])
                        C2[i][j] = 1;

        if (C1 == C2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        
        if (T)
            cout << endl;
    }
    return 0;
}