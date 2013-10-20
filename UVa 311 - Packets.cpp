#include <iostream>
#include <algorithm>
using namespace std;

int main()
{  
    int b1, b2, b3, b4, b5, b6;
    while (cin >> b1 >> b2 >> b3 >> b4 >> b5 >> b6, 
           b1 + b2 + b3 + b4 + b5 + b6 > 0)
    {
        int parcels = 0;
        // b6 boxes.
        parcels += b6;
        // b5 boxes each with 11 1x1.
        parcels += b5;
        b1 -= b5 * 11;
        // b4 boxes each with 5 2x2.
        parcels += b4;
        b2 -= b4 * 5;
        // (b3 + 3) / 4 boxes, then check the last parcel.
        parcels += (b3 + 3) / 4;
        if (b3 % 4 == 1)
        {
            b2 -= 5;
            b1 -= 7;
        }
        else if (b3 % 4 == 2)
        {
            b2 -= 3;
            b1 -= 6;
        }
        else if (b3 % 4 == 3)
        {
            b2 -= 1;
            b1 -= 5;
        }
        // Now handle b2.
        if (b2 > 0)
        {
            parcels += (b2 + 8) / 9;
            b2 -= 9 * ((b2 + 8) / 9);
        }
        // Lastly, handle b1.
        if (b2 < 0)
            b1 += b2 * 4;
        if (b1 > 0)
            parcels += (b1 + 35) / 36;

        cout << parcels << endl;
    }
    return 0;
}