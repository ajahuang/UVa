#include <iostream>
#include <algorithm> 
#include <iomanip> 
#include <cstring> 
using namespace std;

const int MAX_DIGITS = 781;
int digits[2][MAX_DIGITS];

int main()
{    
    int n;
    while (cin >> n, n != 0)
    {
        int resultIndex = 0;
        int resultDigits = 1;
        int lastResultIndex = 1;
       
        digits[resultIndex][0] = 1;
        
        for (int m = 2; m <= n; ++m)
        {
            swap(resultIndex, lastResultIndex);
            memset(digits[resultIndex], 0, sizeof digits[resultIndex]);

            /** Prepare the multiplier[]. 
                For example, m = 86
                multiplier[0] = 6
                multiplier[1] = 8
                multiplierIndex = 2 
            */
            int multiplier[4];
            int tmp = m;
            int multiplierIndex = 0;
            while (tmp)
            {
                multiplier[multiplierIndex++] = tmp % 10;
                tmp /= 10;
            }

            // Multiply digits[lastResultIndex][0..resultDigits] by the multiplier.
            int i = 0, j = 0;
            for ( ; i < multiplierIndex; ++i)
            {
                j = 0;
                int carry = 0;
                for ( ; j < resultDigits || carry > 0; ++j)
                {
                    int product = digits[resultIndex][i + j] + multiplier[i] * digits[lastResultIndex][j] + carry;
                    carry = product / 10;
                    digits[resultIndex][i + j] = product % 10;
                }
            }
            resultDigits = i + j - 1;
        }
        
        // Count the digits.
        int countDigits[10] = {0};
        for (int i = 0; i < resultDigits; ++i)
        {
            ++countDigits[digits[resultIndex][i]];
        }

        cout << n << "! --" << endl;
        for (int i = 0; i <= 9; ++i)
        {
            cout << setw(5) << "(" << i << ")"
                 << setw(5) << countDigits[i];
            if (i == 4 || i == 9)
                cout << endl;
        }
    }
    return 0;
}