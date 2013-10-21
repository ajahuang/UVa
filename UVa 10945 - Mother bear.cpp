#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(const string &s)
{
    string r_s(s);
    reverse(r_s.begin(), r_s.end());
    return s == r_s;
}

bool isIgnoredChar(char c) 
{
    switch(c)
    {
    case ' ':
    case '.':
    case ',':
    case '!':
    case '?':
        return true;
    default:
        return false;
    }
}

int main()
{  
    string s;
    while (getline(cin, s), s != "DONE")
    {
        // Remove ignored chars. 
        s.erase(remove_if(s.begin(), s.end(), isIgnoredChar), s.end());
        // Convert all chars to lowercase.
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        if (isPalindrome(s))
            cout << "You won't be eaten!" << endl;
        else
            cout << "Uh oh.." << endl;
    }
    return 0;
}