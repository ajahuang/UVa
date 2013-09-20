#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> memo;
int code;

// Enumerate the strings of s + one character in a strict 
// lexicographic order.
void enumerateStrings(string s, size_t len)
{
    if (s.size() == len)
    {
        memo[s] = code++;
        return;
    }
    char lastLetter;
    if (s.empty())
        lastLetter = 'a';
    else
        lastLetter = s[s.size() - 1] + 1;

    for (char c = lastLetter; c <= 'z'; ++c)
        enumerateStrings(s + c, len);
}

int main()
{  
    code = 1;
    for (size_t len = 1; len <= 5; ++len)
        enumerateStrings("", len);

    string word;
    while (cin >> word)
        cout << memo[word] << endl;
    
    return 0;
}