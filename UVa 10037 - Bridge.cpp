#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

void print(stringstream &ss, int t1, int t2 = -1)
{
    if (t2 == -1)
        ss << t1 << endl;
    else
        ss << t1 << " " << t2 << endl;
}

int main()
{  
    int T;
    cin >> T;
    while ( T-- )
    {
        int n;
        cin >> n;
        
        vector<int> t(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> t[i];
        
        sort(t.begin(), t.end());

        stringstream ss;
        int c = n;
        int totalTime = 0;
        // In each round consider the fastest 2 people (A and B) and 
        // the slowest 2 people (Y and Z).
        while (c >= 4)
        {
            // <AB> <A> <YZ> <B> 
            int t1 = t[2] + t[1] + t[c] + t[2];
            // <AZ> <A> <AY> <A>
            int t2 = t[c] + t[1] + t[c - 1] + t[1];
            if (t1 < t2)
            {
                totalTime += t1;
                print(ss, t[1], t[2]);
                print(ss, t[1]);
                print(ss, t[c - 1], t[c]);
                print(ss, t[2]);
            }
            else
            {
                totalTime += t2;
                print(ss, t[1], t[c]);
                print(ss, t[1]);
                print(ss, t[1], t[c - 1]);
                print(ss, t[1]);
            }
            c -= 2;
        }
        // <AB> <A> <AC>
        if (c == 3)
        {
            totalTime += t[2] + t[1] + t[3];
            print(ss, t[1], t[2]);
            print(ss, t[1]);
            print(ss, t[1], t[3]);
        }
        // <AB>
        else if (c == 2)
        {
            totalTime += t[2];
            print(ss, t[1], t[2]);
        }
        // <A>
        else
        {
            totalTime += t[1];
            print(ss, t[1]);
        }

        cout << totalTime << endl;
        cout << ss.str();

        if (T)
            cout << endl;
    }
    return 0;
}