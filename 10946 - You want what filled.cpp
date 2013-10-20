#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<vector<char> > vvc_t;
typedef vector<vector<int> >  vvi_t;

const int UNVISITED = 0;
const int VISITED = 1;

int dx[] = {-1, 0, 1,  0};
int dy[] = { 0, 1, 0, -1};

int dfs(vvc_t &map, char h, int x, int y)
{
    map[x][y] = '.';
    int holeSize = 1;
    for (int i = 0; i < 4; ++i)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx < 0 || tx >= map.size() || ty < 0 || ty >= map[0].size())
            continue;
        if (map[tx][ty] == h)
            holeSize += dfs(map, h, tx, ty);
    }
    return holeSize;
}

bool comp(const pair<int, char> &h1, const pair<int, char> &h2)
{
    if (h1.first > h2.first)
        return true;
    else if (h1.first == h2.first && h1.second < h2.second)
        return true;

    return false;
}

int main()
{  
    int Case = 1;
    int x, y;
    while (cin >> x >> y, !(x == 0 && y == 0))
    {
        vvc_t map(x, vector<char>(y));
        for (int r = 0; r < x; ++r)
            for (int c = 0; c < y; ++c)
                cin >> map[r][c];

        vector<pair<int, char> > holes;
        for (int r = 0; r < x; ++r)
            for (int c = 0; c < y; ++c)
                if (map[r][c] != '.')
                {
                    char h = map[r][c];
                    holes.push_back(make_pair(dfs(map, map[r][c], r, c), h));
                }
        // "sorted by the size of the hole, break ties by sorting 
        // the characters in alphabetical order"
        sort(holes.begin(), holes.end(), comp);

        cout << "Problem " << Case++ << ":" << endl;
        for (int i = 0; i < holes.size(); ++i)
            cout << holes[i].second
                 << " "
                 << holes[i].first
                 << endl;
    }
    return 0;
}