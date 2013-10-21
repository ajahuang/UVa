#include <iostream>
#include <string>
using namespace std;

int main()
{  
    size_t T;
    while (cin >> T, T > 0)
    {
        int top = 1, north = 2, west = 3;
        while ( T-- )
        {
            string s;
            cin >> s;  
            //     2
            //   3 1 4 
            //     5
            // 6 is on 1's opposite side.
            int lastTop = top;
            if (s == "north")
            {
                top = 7 - north;
                north = lastTop;
            }
            else if (s == "south")
            {
                top = north;
                north = 7 - lastTop;
            }
            else if (s == "west")
            {
                top = 7 - west;
                west = lastTop;
            }
            else if (s == "east")
            {
                top = west;
                west = 7 - lastTop;
            }
        }
        cout << top << endl;
    }
    return 0;
}