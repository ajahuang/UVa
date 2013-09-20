#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string words[3] = {"one", "two", "three"};

size_t wordsDiff(string s1, string s2)
{
    size_t diff = max(s1.size(), s2.size())
                  - min(s1.size(), s2.size());
    
    for (size_t i = 0; i < min(s1.size(), s2.size()); ++i)
        if (s1[i] != s2[i])
            ++diff;
    
    return diff;
}

int main()
{  
    size_t T;
    cin >> T;
    while ( T-- )
    {
        string word;
        cin >> word;
        for (size_t i = 0; i < 3; ++i)
        {
            if (wordsDiff(word, words[i]) <= 1)
            {
                cout << i + 1 << endl;
                break;
            }
        }
    }
    return 0;
}