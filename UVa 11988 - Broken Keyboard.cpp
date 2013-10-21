#include <iostream>
#include <string>
#include <list>
#include <iterator>
using namespace std;

int main()
{  
    string line;
    while (getline(cin, line))
    {
        list<char> beiju;
        list<char>::iterator iter(beiju.begin());
        for (size_t i = 0; i < line.size(); ++i)
        {
            // "Home" key.
            if (line[i] == '[')
                iter = beiju.begin();
            // "End" key.
            else if (line[i] == ']')
                iter = beiju.end();
            
            /** Using a vector<char> works but will get TLE.    
                
                iter = beiju.insert(iter, line[i]); 
                ++iter;
            */
            else
                beiju.insert(iter, line[i]);                
        }
        copy(beiju.begin(), beiju.end(), ostream_iterator<char>(cout, ""));
        cout << endl;
    }
    return 0;
}