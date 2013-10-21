#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{  
    int W, H, N;
    while (cin >> W >> H >> N, W != 0)
    {
        // Initialize and fill the board with 1.
        vector<vector<int> > board(W, vector<int>(H, 0));
        int emptySpots = W * H;
        for (int i = 0; i < N; ++i)
        {
            int X1, Y1, X2, Y2;
            cin >> X1 >> Y1 >> X2 >> Y2;
            // Reset the sub-portion to 0.
            for (int x = min(X1, X2) - 1; x <= max(X1, X2) - 1; ++x)
                for (int y = min(Y1, Y2) - 1; y <= max(Y1, Y2) - 1; ++y)
                {
                    if (board[x][y] == 0)
                    {
                        --emptySpots;
                        board[x][y] = 1;
                    }
                }
        }
        if (emptySpots == 0)
            cout << "There is no empty spots." << endl;
        else if (emptySpots == 1)
            cout << "There is one empty spot." << endl;
        else
            cout << "There are " 
                 << emptySpots 
                 << " empty spots." 
                 << endl;
    }
    return 0;
}