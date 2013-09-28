#include <iostream>
using namespace std;

int diff(int nowD, int nowM, int nowY,
         int birthD, int birthM, int birthY)
{
    return nowD + 30 * nowM + 360 * nowY 
           - birthD - 30 * birthM - 360 * birthY;
}

int main()
{  
    size_t Case = 1;
    size_t T;
    cin >> T;
    while ( T-- )
    {
        int nowD, nowM, nowY;
        int birthD, birthM, birthY;
        char c;
        cin >> nowD >> c >> nowM >> c >> nowY;
        cin >> birthD >> c >> birthM >> c >> birthY;

        cout << "Case #" << Case++ << ": "; 
        int dateGap = diff(nowD, nowM, nowY, birthD, birthM, birthY);
        if (dateGap < 0)
            cout << "Invalid birth date" << endl;
        else if (dateGap / 360 > 130)
            cout << "Check birth date" << endl;
        else
            cout << dateGap / 360 << endl;    
    }
    return 0;
}