#include <iostream>
#include <cstring>
using namespace std;

int R, C, N;
int dp[5][5][1 << 16];

const int dx[] = {-1, -1, -1,  0, 0,  1, 1, 1};
const int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};

bool isOutOfBoard(int x, int y)
{
    return x <= 0 || y <= 0 || x >= R + 1 || y >= C + 1;
}

int shift(int x, int y)
{
    return (x - 1) * 4 + y - 1;
}

int search(int board)
{
    if ((board & (board - 1)) == 0)
        return 1;

    if (dp[R][C][board] != -1)
        return dp[R][C][board];
    
    int ret = 0;
    for (int x = 1; x <= R; ++x)
        for (int y = 1; y <= C; ++y)
            if (board & (1 << shift(x, y)))
                for (int i = 0; i < 8; ++i)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (isOutOfBoard(nx, ny))
                        continue;
                    if (board & (1 << shift(nx, ny)))
                    {
                        int tx = nx + dx[i];
                        int ty = ny + dy[i];
                        if (isOutOfBoard(tx, ty))
                            continue;
                        if ((board & (1 << shift(tx, ty))) == 0)
                            ret += search(board 
                                          & ~(1 << shift(x, y)) 
                                          & ~(1 << shift(nx, ny)) 
                                          | (1 << shift(tx, ty))
                                          );
                    }
                }

    return dp[R][C][board] = ret;
}

int solve(int initialBoard)
{
    return search(initialBoard);
}

int main()
{
    int T, Case = 1;
    cin >> T;

    // It's important to store the results across different test cases.
    memset(dp, -1, sizeof(dp));

    while ( T-- )
    {
        cin >> R >> C >> N;
     
        int initialBoard = 0;
        for (int i = 1; i <= N; ++i)
        {
            int x, y;
            cin >> x >> y;
            initialBoard |= (1 << shift(x, y)); 
        }

        cout << "Case " << Case++ << ": " 
             << solve(initialBoard) << endl;
    }
    return 0;
} 