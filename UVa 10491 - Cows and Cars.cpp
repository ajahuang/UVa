#include <iostream>
#include <iomanip>
using namespace std;

int main()
{    
    int NCOWS, NCARS, NSHOW;
    while (cin >> NCOWS >> NCARS >> NSHOW)
    {
        // Two cases.
        // 1.Pick a cow and switch to a car:
        //   NCOWS / (NCOWS + NCARS) 
        //   * NCARS / (NCOWS + NCARS - NSHOW - 1)
        // 2.Pick a car and switch to a car:
        //   NCARS / (NCOWS + NCARS)
        //   * (NCARS - 1) / (NCOWS + NCARS - NSHOW - 1)
        cout << setprecision(5)
             << fixed
             << ((double)NCARS * (NCOWS + NCARS - 1)) / ((NCOWS + NCARS) * (NCOWS + NCARS - NSHOW - 1))
             << endl;
    }
    return 0;
}