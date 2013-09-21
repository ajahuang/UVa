#include <iostream>
#include <algorithm>
using namespace std;

int main()
{  
    int N, B, H, W;
    while (cin >> N >> B >> H >> W)
    {
        int minCost = B + 1;
        for (int h = 0; h < H; ++h)
        {
            int p;
            cin >> p;
            for (int w = 0; w < W; ++w)
            {
                int a;
                cin >> a;
                if (a >= N && p * N <= minCost)
                    minCost = p * N;
            }
        }
        if (minCost <= B)
            cout << minCost << endl;
        else
            cout << "stay home" << endl;
    }
    return 0;
}