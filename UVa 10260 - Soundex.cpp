#include <iostream>
#include <string>
using namespace std;

int main()
{  
    // Prepare the mapping of Soundex coding.
    string soundex[6] = { "BFPV", 
                          "CGJKQSXZ",
                          "DT",
                          "L",
                          "MN",
                          "R" };
    size_t soundexSize = sizeof(soundex) / sizeof(soundex[0]);

    string word;
    while (cin >> word)
    {
        string code;
        size_t prevIndex = soundexSize;
        for (size_t i = 0; i < word.size(); ++i)
        {
            size_t j = 0;
            for ( ; j < soundexSize; ++j)
            {
                if (soundex[j].find(word[i]) != string::npos)
                {
                    if (j != prevIndex)
                        code.push_back(static_cast<char>('0' + j + 1));
                    prevIndex = j;
                    break;
                }
            }
            if (j == soundexSize)
                prevIndex = soundexSize;
        }
        cout << code << endl;
    }
    return 0;
}