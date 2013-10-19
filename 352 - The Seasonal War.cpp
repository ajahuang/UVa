#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<int> vi_t;
typedef vector<vi_t> vvi_t;

int dx[] = {-1, -1, -1,  0, 0,  1, 1, 1};
int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};

void dfs(vvi_t &image, int x, int y)
{
    image[x][y] = 0;
    // "Cells with adjacent sides on common vertices, which contain binary ones, 
    // comprise one war eagle." 
    for (int i = 0; i < 8; ++i)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx < 0 || tx >= image.size() || ty < 0 || ty >= image.size())
            continue;
        if (image[tx][ty] == 1)
            dfs(image, tx, ty);
    }
}

int main()
{  
    int Case = 1, n; 
    while (cin >> n)
    {
        cin.ignore();
        
        string s;
        vvi_t image(n, vi_t(n));
        for (int x = 0; x < n; ++x)
        {
            getline(cin, s);
            for (int y = 0; y < n; ++y)
                image[x][y] = s[y] - '0';
        }
        // Use DFS to find connected components.
        int nCC = 0;
        for (int x = 0; x < n; ++x)
            for (int y = 0; y < n; ++y)
                if (image[x][y] == 1)
                {
                    ++nCC;
                    dfs(image, x, y);
                }

        cout << "Image number " 
             << Case++
             << " contains "
             << nCC
             << " war eagles."
             << endl;
    }
    return 0;
}