#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x,
         double p,
         double q,
         double r,
         double s,
         double t,
         double u)
{
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main()
{  
    double p, q, r, s, t, u;
    while (cin >> p >> q >> r >> s >> t >> u)
    {
        // Perform Bisection Method.
        // f(0) = 1, f(1) = -1.
        double U = 1.0, L = 0.0;
        while (U - L >= 1e-9)
        {
            double m = (L + U) / 2.0;
            double value = f(m, p, q, r, s, t, u);
            if (value < 0)
                U = m;
            else
                L = m;
        }
        if (abs(f((L + U) / 2, p, q, r, s, t, u)) <= 1e-4)
            cout << setprecision(4)
                 << fixed
                 << (L + U) / 2.0 
                 << endl;
        else
            cout << "No solution" << endl;
    }
    return 0;
}