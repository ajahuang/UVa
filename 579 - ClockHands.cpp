#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{  
    int h, m;
    char c;
    while (cin >> h >> c >> m, h != 0 || m != 0)
    {
        double hAngle = (360.0 / 12) * h + ((360.0 / 12) / 60) * m;
        double mAngle = (360.0 / 60) * m;
        double angle = max(hAngle - mAngle, mAngle - hAngle); 
        cout << setprecision(3)
             << fixed
             << min(angle, 360.0 - angle)
             << endl;
    }
    return 0;
}