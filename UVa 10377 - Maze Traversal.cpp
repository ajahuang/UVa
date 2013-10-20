#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

static const char WALL = '*';
static const char DIR[] = {'N', 'E', 'S', 'W'};
static const int DX[] = {-1, 0, 1,  0};
static const int DY[] = { 0, 1, 0, -1};

void F(const vector<vector<char> > &maze,
       int &x, int &y, int dir)
{
    int tx = x + DX[dir];
    int ty = y + DY[dir];
    if (maze[tx][ty] == WALL)
        return;
    else
    {
        x = tx;
        y = ty;
    }
}

int main()
{  
    int T;
    cin >> T;
    while ( T-- )
    {
        int m, n;
        cin >> m >> n;
        cin.ignore();
        
        vector<vector<char> > maze(m + 1, vector<char>(n + 1));
        for (int x = 1; x <= m; ++x)
        {
            string s;
            getline(cin, s);
            for (int y = 1; y <= n; ++y)
                maze[x][y] = s[y - 1];
        }

        int posX, posY;
        int dir = 0;
        cin >> posX >> posY;
        cin.ignore();
        
        string s;
        while (getline(cin, s))
        {
            // Remove all empty spaces.
            s.erase(remove(s.begin(), s.end(), ' '), s.end());
            for (size_t i = 0; i < s.size(); ++i)
            {
                if (s[i] == 'R')
                    dir = (dir + 1) % 4;
                else if (s[i] == 'L')
                    dir = (dir + 3) % 4;
                else if (s[i] == 'F')
                    F(maze, posX, posY, dir);
                else
                    cout << posX << " " << posY << " " << DIR[dir] << endl;
            }
            if (s[s.size() - 1] == 'Q')
                break;
        }
        if (T)
            cout << endl;
    }
    return 0;
}