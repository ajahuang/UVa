#include <iostream>
#include <string>
using namespace std;

int main()
{  
    // Prepare the mapping of Soundex coding.
    char digits[26] = {0};
    digits['B'-'A'] = digits['F'-'A'] 
                    = digits['P'-'A']
                    = digits['V'-'A']
                    = '1';
    digits['C'-'A'] = digits['G'-'A']
                    = digits['J'-'A']
                    = digits['K'-'A']
                    = digits['Q'-'A']
                    = digits['S'-'A']
                    = digits['X'-'A']
                    = digits['Z'-'A']
                    = '2';
    digits['D'-'A'] = digits['T'-'A'] 
                    = '3';
    digits['L'-'A'] = '4';
    digits['M'-'A'] = digits['N'-'A'] 
                    = '5';
    digits['R'-'A'] = '6';

    string word;
    while (cin >> word)
    {
        string code;
        char lastLetter = ' ';
        for (size_t i = 0; i < word.size(); ++i)
        {
            size_t target = word[i] - 'A';
            // "repeated letters with the same code digit are 
            // represented by a single instance of that digit."
            if (digits[target] != 0
                && digits[target] != digits[lastLetter - 'A'])
            {
                code.push_back(digits[target]);
            }
            lastLetter = word[i];
        }
        cout << code << endl;
    }
    return 0;
}