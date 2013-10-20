#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{  
    string line;
    while (getline(cin, line), line != "0")
    {
        size_t N;
        // Convert line to N.
        istringstream(line) >> N;
        vector<string> image;
        for (size_t i = 0; i < N; ++i)
        {
            getline(cin, line);
            image.push_back(line);
        }
        size_t totalB = 0;
        size_t minB = 25;
        for (size_t i = 0; i < N; ++i)
        {
            size_t countB = count(image[i].begin(), image[i].end(), ' ');
            totalB += countB;
            minB = min(minB, countB);
        }
        cout << totalB - N * minB << endl;
    }
    return 0;
}