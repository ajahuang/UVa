#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{  
    size_t T;
    cin >> T;
    while ( T-- )
    {
        size_t n;
        cin >> n;
        vector<int> instructions;
        int position = 0;
        while ( n-- )
        {
            string instruction;
            cin >> instruction;
            if (instruction == "LEFT")
            {
                --position;
                instructions.push_back(-1);
            }
            else if (instruction == "RIGHT")
            {
                ++position;
                instructions.push_back(1);
            }
            // "SAME AS .."
            else
            {
                 int i;
                 cin >> instruction >> i;
                 position += instructions[i - 1];
                 // Store the action directly.
                 instructions.push_back(instructions[i - 1]);
            }
        }
        cout << position << endl;
    }
    return 0;
}