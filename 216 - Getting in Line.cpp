#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits>
#include <iomanip>
using namespace std;

/** This problem is easy, but many details need to be handled carefully, particularly
    the output format. */

struct computer 
{
    int x, y;
};

double dist(const computer &a, const computer &b)
{
    // "plus 16 additional feet of cable.."
    return 16.0 + sqrt((double)(a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{   
    int T = 1;
    int N;
    while (cin >> N, N > 0)
    {
        vector<computer> computers;
        vector<int> computerIndexes;
        for (int i = 1; i <= N; ++i)
        {
            computer com;
            cin >> com.x >> com.y;
            computers.push_back(com);
            computerIndexes.push_back(i - 1);
        }

        // Loop over all permutations.
        vector<int> network;
        double minimumCable = numeric_limits<double>::max();
        do {
            double cable = 0;
            for (int i = 0; i < N - 1; ++i)
                cable += dist(computers[computerIndexes[i]], computers[computerIndexes[i + 1]]);

            if (cable < minimumCable)
            {
                minimumCable = cable;
                network = computerIndexes;
            }
        } while (next_permutation(computerIndexes.begin(), computerIndexes.end()));

        cout << "**********************************************************" << endl;
        cout << "Network #" << T++ << endl;
        for (int i = 0; i < N - 1; ++i)
            cout << "Cable requirement to connect "
                 << "(" 
                 << computers[network[i]].x
                 << ","
                 << computers[network[i]].y
                 << ") to ("
                 << computers[network[i + 1]].x
                 << ","
                 << computers[network[i + 1]].y
                 << ") is "
                 << setprecision(2)
                 << setiosflags(ios::fixed)
                 << dist(computers[network[i]], computers[network[i + 1]])
                 << " feet."
                 << endl;
        cout << "Number of feet of cable required is "
             << setprecision(2)
             << setiosflags(ios::fixed)
             << minimumCable
             << "."
             << endl;
    }
    return 0;
}