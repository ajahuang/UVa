#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void BtoD(const vector<vector<int> > &bm,
          int Rs, int Re, int Cs, int Ce, int &p)
{
    // Ignore 0-by-0 bitmap.
    if (Rs == Re || Cs == Ce)
        return;

    int zeros = 0;
    for (int r = Rs; r < Re; ++r)
        zeros += static_cast<int>(count(bm[r].begin() + Cs, bm[r].begin() + Ce, 0));

    // "Each line will contain 50 characters."
    if (p > 0 && p % 50 == 0)
        cout << endl;
    ++p;
    if (zeros == (Re - Rs) * (Ce - Cs))
        cout << "0";
    else if (zeros == 0)
        cout << "1";
    else
    {
        cout << "D";
        int rHalf = (Rs + Re + 1) / 2;
        int cHalf = (Cs + Ce + 1) / 2;
        BtoD(bm, Rs, rHalf, Cs, cHalf, p);
        BtoD(bm, Rs, rHalf, cHalf, Ce, p);
        BtoD(bm, rHalf, Re, Cs, cHalf, p);
        BtoD(bm, rHalf, Re, cHalf, Ce, p);
    }
}

void DtoB(vector<vector<int> > &bm,
          int Rs, int Re, int Cs, int Ce)
{
    if (Rs == Re || Cs == Ce)
        return;

    // Get 1 char from cin.
    int ch = cin.get();
    if (ch == '0' || ch == '1')
    {
        for (int r = Rs; r < Re; ++r)
            for (int c = Cs; c < Ce; ++c)
                bm[r][c] = ch - '0';
        return;
    }
    else
    {
        int rHalf = (Rs + Re + 1) / 2;
        int cHalf = (Cs + Ce + 1) / 2;
        DtoB(bm, Rs, rHalf, Cs, cHalf);
        DtoB(bm, Rs, rHalf, cHalf, Ce);
        DtoB(bm, rHalf, Re, Cs, cHalf);
        DtoB(bm, rHalf, Re, cHalf, Ce);
    }
}

int main()
{  
    char type;
    while (cin >> type, type != '#')
    {
        int row, col;
        cin >> row >> col;
        cin.ignore();

        cout << (type == 'B'? "D" : "B") 
             << right << setw(4) << row  
             << right << setw(4) << col 
             << endl;

        vector<vector<int> > bm(row, vector<int>(col));       
        if (type == 'B')
        {
            string s;
            while (s.size() < row * col)
            {
                string tmp;
                getline(cin, tmp);
                s = s + tmp;
            }
            for (int r = 0; r < row; ++r)
                for (int c = 0; c < col; ++c)
                    bm[r][c] = s[r * col + c] - '0';
            // p indicates how many characters have been printed.
            int p = 0;
            BtoD(bm, 0, row, 0, col, p);
            cout << endl;
        }
        else
        {
            DtoB(bm, 0, row, 0, col);
            for (int r = 0; r < row; ++r)
                for (int c = 0; c < col; ++c)
                {
                    // "Each line will contain 50 characters."
                    if (r + c > 0 && (r * col + c) % 50 == 0)
                        cout << endl;
                    cout << bm[r][c];
                }
            cout << endl;
        }
    }
    return 0;
}