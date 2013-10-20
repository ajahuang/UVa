#include <iostream>
using namespace std;

static const int DEGREE_PER_MARK = 360 / 40;
enum DIRECTION {
    CLOCKWISE, 
    COUNTER_CLOCKWISE
};


int turn(int from, int to, DIRECTION dir)
{
    if (dir == CLOCKWISE)
    {
        if (to >= from)
            return (from + (40 - to)) * DEGREE_PER_MARK;
        else
            return (from - to) * DEGREE_PER_MARK;
    }
    else
    {
        if (to >= from)
            return (to - from) * DEGREE_PER_MARK;
        else
            return ((40 - from) + to) * DEGREE_PER_MARK;
    }
}

int main()
{  
    int p1, p2, p3, p4;
    while (cin >> p1 >> p2 >> p3 >> p4, p1 + p2 + p3 + p4 > 0)
    {
        // Turn the dial clockwise 2 full turns.
        int totalDegree = 360 * 2;
        totalDegree += turn(p1, p2, CLOCKWISE);
        // Turn the dial counter-clockwise 1 full turn.
        totalDegree += 360;
        totalDegree += turn(p2, p3, COUNTER_CLOCKWISE);
        totalDegree += turn(p3, p4, CLOCKWISE);
        cout << totalDegree << endl;
    }
    return 0;
}