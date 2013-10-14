#include <iostream>
#include <vector>
using namespace std;

int main()
{  
    int T, Case = 1;
    cin >> T;
    while ( T-- )
    {
        int N;
        cin >> N;
        vector<char> field(N + 2, '#');
        for (int i = 0; i < N; ++i)
            cin >> field[i];

        int scarecrows = 0;
        for (int i = 0; i < N; ++i)
        {
            // Greedily make a scarecrow cover 3 cells. 
            if (field[i] == '.')
            {
                field[i] = field[i + 1] = field[i + 2] = '#';
                ++scarecrows;
            }
        }
        cout << "Case "
             << Case++
             << ": "
             << scarecrows  
             << endl;
    }
    return 0;
}