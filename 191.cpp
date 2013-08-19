#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

/**
    Using cross products would be much simplier to solve this problem. In this solution,
    I practiced geometry basics without cross products.

    There is a bug in UVA's official answer (http://www.uvatoolkit.com/problemssolve.php).
    This case should output "T" (since the line segment intersects with the rectangle at (-1, -3))
    , but the official answer output "F":

    2 -5 -10 3 -1 0 2 -3
*/

static const double EPS = 1e-9;

/** Model a point of integer coordinates. */
struct Point { double x, y; };

/** Model a linear equation ax + by + c = 0. 
    a is the slope. 
    b = 0 if it is a vertical line; otherwise b = 1.
*/
struct Line { double a, b, c; };

/** Given p1 and p2, compute the linear equation and store it in l. */ 
void pointsToLine(Point p1, Point p2, Line &l) 
{
    // l is a vertial line.
    if (p1.x == p2.x)
    {
        l.a = 1.0;
        l.b = 0;
        l.c = -p1.x;
    }
    else 
    {
        l.a = -(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(l.a * p1.x) - p1.y;
    }
}

bool areSame(Line l1, Line l2)
{
    return (fabs(l1.a - l2.a) < EPS 
            && fabs(l1.b - l2.b) < EPS
            && fabs(l1.c - l2.c) < EPS);
}

/** If l1 and l2 are not parallel, return true and store their intersected 
    point in p; otherwise return false. */
bool areIntersected(Line l1, Line l2, Point &p) {

    // If l1 and l2 are parallel, return false.
    if (fabs(l1.a - l2.a) < EPS 
        && fabs(l1.b - l2.b) < EPS)
        return false;

    // Solve the system of two linear algebraic equations.
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);

    if (fabs(l1.b) > EPS)
        p.y = -(l1.a * p.x + l1.c);
    else
        p.y = -(l2.a * p.x + l2.c);

    return true;
}

/** Return the Euclidean distance between p1 and p2. */
double dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) 
                 + (p1.y - p2.y) * (p1.y - p2.y));
}

/** Given p1, p2 and p3 are collinear, is p3 on the segment formed between p1 and p2? */
bool isOnSegment(Point p1, Point p2, Point p3)
{
    if (dist(p1, p3) - EPS <= dist(p1, p2)
        && dist(p2, p3) - EPS <= dist(p1, p2))
        return true;

    return false;
}

/** Is p3 inside the rectangle formed by left-top p1 and right-bottom p2? */
bool isInsideRectangle(Point p1, Point p2, Point p3)
{
    if (p3.x <= max(p1.x, p2.x)
        && p3.x >= min(p1.x, p2.x)
        && p3.y <= max(p1.y, p2.y)
        && p3.y >= min(p1.y, p2.y))
        return true;

    return false;
}

int main()
{    
    int n;
    cin >> n;

    while ( n-- )
    {
        Point line[2];
        Point rectangle[4];

        cin >> line[0].x >> line[0].y 
            >> line[1].x >> line[1].y;
        cin >> rectangle[0].x >> rectangle[0].y 
            >> rectangle[2].x >> rectangle[2].y;

        // Is line[0] or line[1] inside the rectangle?
        if (isInsideRectangle(rectangle[0], rectangle[2], line[0])
            || isInsideRectangle(rectangle[0], rectangle[2], line[1]))
        {
            cout << "T" << endl;
            continue;
        }
        
        // Now check intersections.
        rectangle[1] = rectangle[0];
        rectangle[3] = rectangle[2];
        swap(rectangle[1].y, rectangle[3].y);

        Line lineSegment;
        pointsToLine(line[0], line[1], lineSegment);
        bool intersect = false;
        // Loop over every edge of the rectangle.
        for (int i = 0; i < 4; ++i) 
        {
            // Compute the equation of this edge.
            Line rectangleEdge;
            pointsToLine(rectangle[i], rectangle[(i + 1) % 4], rectangleEdge);

            // If the equations are the same, check if the two segments overlap.
            if (areSame(lineSegment, rectangleEdge))
            {
                if (isOnSegment(line[0], line[1], rectangle[i])
                    || isOnSegment(line[0], line[1], rectangle[(i + 1) % 4]))
                {
                    intersect = true;
                    break;
                }
                continue;
            }

            // Otherwise, check if they intersect and the intersection is inside both segments.
            Point p;
            if (areIntersected(lineSegment, rectangleEdge, p)) 
            {
                if (isOnSegment(line[0], line[1], p)
                    && isOnSegment(rectangle[i], rectangle[(i + 1) % 4], p))
                {
                    intersect = true;
                    break;
                }
            }
        }

        if (intersect)
            cout << "T" << endl;
        else
            cout << "F" << endl;
    }
    return 0;
}