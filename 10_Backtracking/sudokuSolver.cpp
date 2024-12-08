#include "bits/stdc++.h"
using namespace std;
#define mod 1e9 + 7
#define INF 1000000000000000003

bool checker(vector<vector<string>> &sudoku, int x, int y, string val)
{
    for (int i = 0; i < 9; i++)
        if (sudoku[i][y] == val || sudoku[x][i] == val)
            return false;
    int a = int(x / 3) * 3;
    int b = int(y / 3) * 3;
    for (int i = a; i < a + 3; i++)
        for (int j = b; j < b + 3; j++)
            if (sudoku[i][j] == val)
                return false;
    return true;
}

bool solve(vector<vector<string>> &sudoku)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sudoku[i][j] == ".")
            {
                for (int k = 1; k <= 9; k++)
                {
                    string p = to_string(k);
                    if (checker(sudoku, i, j, p))
                    {
                        sudoku[i][j] = p;
                        if (solve(sudoku))
                            return true;
                        else
                            sudoku[i][j] = ".";
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<string>> sudoku = {
        {"5", "3", ".", ".", "7", ".", ".", ".", "."},
        {"6", ".", ".", "1", "9", "5", ".", ".", "."},
        {".", "9", "8", ".", ".", ".", ".", "6", "."},
        {"8", ".", ".", ".", "6", ".", ".", ".", "3"},
        {"4", ".", ".", "8", ".", "3", ".", ".", "1"},
        {"7", ".", ".", ".", "2", ".", ".", ".", "6"},
        {".", "6", ".", ".", ".", ".", "2", "8", "."},
        {".", ".", ".", "4", "1", "9", ".", ".", "5"},
        {".", ".", ".", ".", "8", ".", ".", "7", "9"}};
    solve(sudoku);
    for (auto i : sudoku)
    {
        for (auto j : i)
            cout << j << " ";
        cout << "\n";
    }
    return 0;
}
