#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;

int love(string s)
{
    int sum = 0;
    for (size_t i = 0; i < s.size(); ++i)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            sum += s[i] - 'a' + 1;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            sum += s[i] - 'A' + 1;
    }
    // Using modulo 9 to efficiently compute digit's sum.
    if (sum % 9 == 0)
        return 9;
    else
        return sum % 9;
}

int main()
{  
    string s1, s2;
    // Note that the input can be an empty string, but
    // cin >> s1 won't take an empty string.
    while (getline(cin, s1))
    {
        getline(cin, s2);
        int r1 = love(s1), r2 = love(s2);
        double ratio = min((double)r1 / r2, (double)r2 / r1);

        cout << setprecision(2)
             << setiosflags(ios_base::fixed)
             << ratio * 100.0
             << " %"
             << endl;
    }
    return 0;
}