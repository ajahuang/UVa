#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Interval
{
    double L, R;
};

bool comp(const Interval &i1, const Interval &i2)
{
    return i1.L < i2.L;
}

int main()
{  
    size_t n, l, w;
    while (cin >> n >> l >> w)
    {
        vector<Interval> circles(1);
        for (size_t i = 0; i < n; ++i)
        {
            double pos, radius;
            cin >> pos >> radius;
            // Calculate this circle's effective interval [L, R].
            // Then this problem is identical to 10020 - Minimal coverage.
            double range = sqrt(radius * radius - (w / 2.0) * (w / 2.0));
            circles[0].L = pos - range;
            circles[0].R = pos + range;
            circles.push_back(circles[0]);
        }
        // Sort the circles by increasing left endpoint. 
        sort(circles.begin() + 1, circles.end(), comp);

        double curL = 0, rReach = 0;
        size_t i = 1;
        size_t nSprinklers = 0; 
        while (rReach < l)
        {
            double newCurL = curL;
            size_t farthest = 0;
            // Take the interval that covers as far right as possible.
            for (; i < circles.size(); ++i)
            {
                if (circles[i].L > curL)
                    break;
                if (circles[i].R >= newCurL)
                {
                    newCurL = circles[i].R;
                    farthest = i;
                }
            }
            if (farthest == 0)
                break;
            ++nSprinklers;
            rReach = curL = newCurL;
        }
        if (rReach < l)
            cout << "-1" << endl;
        else
            cout << nSprinklers << endl;
    }
    return 0;
}