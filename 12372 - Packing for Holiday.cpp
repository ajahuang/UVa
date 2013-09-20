#include <iostream>
using namespace std;

int main()
{  
    size_t T;
    size_t Case = 1;
    cin >> T;
    while ( T-- )
    {
        int L, W, H;
        cin >> L >> W >> H;
        cout << "Case " 
             << Case++ 
             << ": "
             << (max(L, max(W, H)) <= 20? "good" : "bad") 
             << endl;
    }
    return 0;
}