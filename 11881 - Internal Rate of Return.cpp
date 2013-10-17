#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <cmath>
using namespace std;

static const double EPS = 1e-9;

double NPV(const vector<double> CF, int T, double IRR)
{
    double npv = CF[0];
    for (int i = 1; i <= T; ++i)
        npv += CF[i] / pow(1.0 + IRR, i);
    
    return npv;
}

int main()
{  
    int T;
    while (cin >> T, T != 0)
    {
        vector<double> CF(T + 1);
        for (int i = 0; i <= T; ++i)
            cin >> CF[i];

        // Bisection method.
        double L = -0.99, U = numeric_limits<double>::max(), IRR = -1.0;
        while (L <= U + EPS)
        {
            double M = (L + U) / 2.0;
            double npv = NPV(CF, T, M);
            if (abs(npv) <= EPS)
            {
                IRR = M;
                break;
            }
            if (npv > EPS)
                L = M;
            else
                U = M;
        }      
        if (abs(IRR + 1.0) <= EPS)
            cout << "No" << endl;
        else
            cout << setprecision (2)
                 << fixed
                 << IRR
                 << endl;
    }
    return 0;
}