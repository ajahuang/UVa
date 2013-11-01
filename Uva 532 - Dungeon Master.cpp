#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct Position
{
    int L;
    int R;
    int C;

    // for map.
    bool operator<(const Position &p) const 
    {
        if (this->L < p.L)
            return true;
        else if (this->L == p.L)
        {
            if (this->R < p.R)
                return true;
            else if (this->R == p.R)
            {
                if (this->C < p.C)
                    return true;
            }
        }
        return false;
    }
};

Position operator+(const Position &p1, const Position &p2)
{
    Position p;
    p.L = p1.L + p2.L;
    p.R = p1.R + p2.R;
    p.C = p1.C + p2.C;
    return p;
}

Position dir[] = { {0, 0, 1}, 
                   {0, 0, -1},
                   {1, 0, 0},
                   {-1, 0, 0},
                   {0, 1, 0},
                   {0, -1, 0}};

int main()
{  
    int L, R, C;
    while (cin >> L >> R >> C, L + R + C > 0)
    {
        map<Position, char> dungeon;
        Position sPos, ePos;

        for (int l = 0; l < L; ++l)
            for (int r = 0; r < R; ++r)
                for (int c = 0; c < C; ++c)
                {
                    Position p;
                    p.L = l;
                    p.R = r;
                    p.C = c;
                    cin >> dungeon[p];
                    if (dungeon[p] == 'S')
                        sPos = p;
                    else if (dungeon[p] == 'E')
                        ePos = p;
                }

        // BFS.
        queue<Position> q;
        map<Position, int> dist;
        
        dist[sPos] = 0;
        q.push(sPos);
        while (!q.empty() && !dist.count(ePos))
        {
            Position u = q.front();
            q.pop();
            for (int i = 0; i < 6; ++i)
            {
                Position v = u + dir[i];
                if (dungeon.count(v) 
                    && dungeon[v] != '#'
                    && !dist.count(v))
                {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        if (dist.count(ePos))
            cout << "Escaped in "
                 << dist[ePos]
                 << " minute(s)."
                 << endl;
        else
            cout << "Trapped!" 
                 << endl;
    }
    return 0;
}