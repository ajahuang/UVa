#include <iostream>
using namespace std;

int main()
{  
    size_t K;
    while (cin >> K, K > 0)
    {
        int N, M;
        cin >> N >> M;
        for (size_t i = 0; i < K; ++i)
        {
            int n, m;
            cin >> n >> m;
            if (n == N || m == M)
                cout << "divisa";
            else if (m > M)
            {
                if (n > N)
                    cout << "NE";
                else 
                    cout << "NO";
            }
            else if (n > N)
                cout << "SE";
            else
                cout << "SO";
            cout << endl;
        }
    }
    return 0;
}