#include <iostream>
#include <string>
#include <sstream>
#include <functional>
#include <algorithm>
using namespace std;

bool isPalindrome(const string &s)
{
    // Locate the first char that is greater than '0'.
    string::const_iterator iter(find_if(s.begin(), s.end(), 
                                        bind2nd(greater<char>(), '0')));
    string::const_reverse_iterator r_iter(s.rbegin());
    // Loop until iter and r_iter cross each other.
    for (; distance(s.begin(), r_iter.base()) 
           > distance(s.begin(), iter); ++iter, ++r_iter)
    {
        if (*iter != *r_iter)
            return false;
    }
    return true;
}

string NextPT(int hour, int min)
{
    for (int h = hour; h < 24; ++h)
    {
        for (int m = min + 1; m < 60; ++m)
        {
            stringstream ss;
            if (h < 10)
                ss << "0";
            ss << h;
            if (m < 10)
                ss << "0";
            ss << m;
            // Insert ":" in the middle.
            if (isPalindrome(ss.str()))
                return ss.str().insert(2, ":");
        }
        min = -1;
    }
    return "00:00";
}

int main()
{  
    size_t n;
    cin >> n;
    while ( n-- )
    {
        int h, m;
        char c;
        cin >> h >> c >> m;
        cout << NextPT(h, m) << endl;
    }
    return 0;
}