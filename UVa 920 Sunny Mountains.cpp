#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

struct Point { int x, y; };

// Return the Euclidean distance between a and b.
double dist(Point a, Point b)
{
    return sqrt((double)(a.x - b.x) * (a.x - b.x)
                      + (a.y - b.y) * (a.y - b.y));
}

bool comp(const Point &a, const Point &b)
{
    return b.x < a.x;
}

int main()
{    
    int C;
    cin >> C;
    while ( C-- )
    {
        int N;
        cin >> N;
        vector<Point> points;
        for (int i = 1; i <= N; ++i)
        {
            Point point;
            cin >> point.x >> point.y;
            points.push_back(point);
        }

        // Sort the points in descending order of x-coordinate.
        sort(points.begin(), points.end(), comp);

        /** 
           points[i].y
            \*
             \* ---  currentMaxY
              \
               \
               points[i - 1].y

            The line segment marked by * can be computed by 

            distance(points[i], points[i - 1]) * 
            (points[i].y - currentMaxY) / (points[i].y - points[i - 1].y)
        */
        int currentMaxY = 0;
        double length = 0;
        for (int i = 1; i < points.size(); ++i)
        {
            if (points[i].y > currentMaxY)
            {
                length += dist(points[i], points[i - 1]) 
                          * (points[i].y - currentMaxY) / (points[i].y - points[i - 1].y); 
                currentMaxY = points[i].y;
            }
        }

        // Print with two decimal digits.
        cout << setprecision(2)
             << setiosflags(ios::fixed)
             << length << endl;
    }
    return 0;
}