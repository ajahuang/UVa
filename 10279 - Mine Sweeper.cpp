#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{  
    size_t T;
    cin >> T;
    while ( T-- )
    {
        size_t n;
        cin >> n;
        vector<vector<char> > board(n + 2, vector<char>((n + 2), '.'));
        vector<vector<char> > game(n + 2, vector<char>((n + 2), '.'));
        bool gameOver = false;
        for (size_t r = 1; r <= n; ++r)
            for (size_t c = 1; c <= n; ++c)
                cin >> board[r][c];

        for (size_t r = 1; r <= n; ++r)
            for (size_t c = 1; c <= n; ++c)
            {
                char g;
                cin >> g;
                // Oops, a mine has been touched.
                if (g == 'x' && board[r][c] == '*')
                    gameOver = true;
                game[r][c] = g;
            }
        for (size_t r = 1; r <= n; ++r)
        {
            for (size_t c = 1; c <= n; ++c)
            {
                if (board[r][c] == '*')
                    cout << (gameOver? '*' : '.');
                else if (game[r][c] == '.')
                    cout << '.';
                else
                {
                    int mines = 0;
                    for (size_t i = r - 1; i <= r + 1; ++i)
                        for (size_t j = c - 1; j <= c + 1; ++j)
                        {
                            if (board[i][j] == '*')
                                ++mines;
                        }
                    cout << mines;
                }
            }
            cout << endl;
        }
        if (T)
            cout << endl;
    }
        
    return 0;
}