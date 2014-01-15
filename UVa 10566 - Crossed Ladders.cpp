#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double EPS = 1e-9;

int main()
{
    double x, y, c;
    while (cin >> x >> y >> c)
    {
        double U = x < y? x : y;
        double L = 0;
        while (U >= L)
        {
            // M is the guessed width.
            // W is the accordingly calculated width.
            double M = (L + U) / 2;
            double W = c / sqrt(x * x - M * M) * M 
                       + c / sqrt(y * y - M * M) * M;

            if (abs(W - M) < EPS)
            {
                cout << setprecision(3) << fixed << W << endl;
                break;
            }
            (W > M? U : L) = M;
        }    
    }
    return 0;
} 