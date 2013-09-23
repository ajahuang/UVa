#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

static map<char, char> mirror;

bool isPalindrome(const string &s)
{
    string r_s(s);
    reverse(r_s.begin(), r_s.end());
    return s == r_s;
}

bool isMirrored(const string &s)
{
    string::const_iterator iter(s.begin());
    string::const_reverse_iterator r_iter(s.rbegin());
    // Need to check the middle element for odd sizes of strings.
    for ( ; iter < s.begin() + (s.size() + 1) / 2; ++iter, ++r_iter)
        if (!mirror.count(*iter) || mirror[*iter] != *r_iter)
            return false;

    return true;
}

int main()
{  
    char from[] = {'A', 'E', 'H', 'I', 'J', 'L',
                   'M', 'O', 'S', 'T', 'U', 'V',
                   'W', 'X', 'Y', 'Z', '1', '2',
                   '3', '5', '8'};
    char to[]   = {'A', '3', 'H', 'I', 'L', 'J',
                   'M', 'O', '2', 'T', 'U', 'V',
                   'W', 'X', 'Y', '5', '1', 'S', 
                   'E', 'Z', '8'};

    for (size_t i = 0; i < sizeof(from) / sizeof(char); ++i)
        mirror[from[i]] = to[i];

    string s;
    while (cin >> s)
    {
        bool isPalin = isPalindrome(s);
        bool isMir = isMirrored(s);
        
        cout << s << " -- "; 
        if (!isPalin && !isMir)
            cout << "is not a palindrome." << endl;
        else if (isPalin && !isMir)
            cout << "is a regular palindrome." << endl;
        else if (!isPalin && isMir)
            cout << "is a mirrored string." << endl;
        else 
            cout << "is a mirrored palindrome." << endl;

        // "after each output line, you must print an empty line."
        cout << endl;
    }
    return 0;
}