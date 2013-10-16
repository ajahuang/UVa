#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void BtoD(const vector<vector<int> > &bitmap,
          int Rs, int Re, int Cs, int Ce,
          int &p)
{
    // Ignore 0-by-0 bitmap.
    if (Rs == Re || Cs == Ce)
        return;

    int zeros = 0;
    for (int r = Rs; r < Re; ++r)
        zeros += static_cast<int>(count(bitmap[r].begin() + Cs, bitmap[r].begin() + Ce, 0));

    // "Each line will contain 50 characters."
    if (p > 0 && p % 50 == 0)
        cout << endl;
    if (zeros == (Re - Rs) * (Ce - Cs))
    {
        cout << "0";
        ++p;
    }
    else if (zeros == 0)
    {
        cout << "1";
        ++p;
    }
    else
    {
        cout << "D";
        ++p;
        int rHalf = (Rs + Re + 1) / 2;
        int cHalf = (Cs + Ce + 1) / 2;
        BtoD(bitmap, Rs, rHalf, Cs, cHalf, p);
        BtoD(bitmap, Rs, rHalf, cHalf, Ce, p);
        BtoD(bitmap, rHalf, Re, Cs, cHalf, p);
        BtoD(bitmap, rHalf, Re, cHalf, Ce, p);
    }
}

void DtoB(vector<vector<int> > &bitmap,
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
                bitmap[r][c] = ch - '0';
        return;
    }
    else
    {
        int rHalf = (Rs + Re + 1) / 2;
        int cHalf = (Cs + Ce + 1) / 2;
        DtoB(bitmap, Rs, rHalf, Cs, cHalf);
        DtoB(bitmap, Rs, rHalf, cHalf, Ce);
        DtoB(bitmap, rHalf, Re, Cs, cHalf);
        DtoB(bitmap, rHalf, Re, cHalf, Ce);
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
             << right 
             << setw(4) 
             << row  
             << right
             << setw(4)
             << col 
             << endl;

        vector<vector<int> > bitmap(row, vector<int>(col));
        
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
                    bitmap[r][c] = s[r * col + c] - '0';
            // p indicates how many characters have been printed.
            int p = 0;
            BtoD(bitmap, 0, row, 0, col, p);
            cout << endl;
        }
        else
        {
            DtoB(bitmap, 0, row, 0, col);
            for (int r = 0; r < row; ++r)
                for (int c = 0; c < col; ++c)
                {
                    // "Each line will contain 50 characters."
                    if (r + c > 0 && (r * col + c) % 50 == 0)
                        cout << endl;
                    cout << bitmap[r][c];
                }
            cout << endl;
        }
    }
    return 0;
}