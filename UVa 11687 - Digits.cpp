#include <iostream>
#include <string>
#include <sstream>
using namespace std;

size_t recurrence(int i, string number)
{
    size_t nDigits = number.size();
    
    ostringstream ss;
    ss << nDigits;
    
    if (ss.str() == number) 
        return i;
    return recurrence(i + 1, ss.str());
}

int main()
{  
    string number;
    while (cin >> number, number != "END")
    {
        cout << recurrence(1, number) << endl;
    }
    return 0;
}