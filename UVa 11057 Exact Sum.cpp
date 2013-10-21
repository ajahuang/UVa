#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{  
    size_t N;
    while (cin >> N)
    {
        vector<int> books(N);
        for (size_t b = 0; b < N; ++b)
            cin >> books[b];

        int M;
        cin >> M;

        sort(books.begin(), books.end());
        int i = books.front();
        int j = books.back();
        for (size_t b = 0; b < N; ++b)
        {
            int b1 = books[b];
            int b2 = M - b1;
            if (b1 > b2)
                break;
            // Search the books after b.
            if (binary_search(books.begin() + b + 1, books.end(), b2))
            {
                if (b2 - b1 < j - i)
                {
                    i = b1;
                    j = b2;
                }
            }
        }
        cout << "Peter should buy books whose prices are "
             << i
             << " and "
             << j
             << "."
             << endl 
             << endl;
    }
    return 0;
}