#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

class Solution
{
public:
    vector<vector<string>> solutions;

    vector<string> makeBoard(int n)
    {
        vector<string> board;
        string row = "";
        for (int i = 0; i < n; i++)
            row += '.';
        for (int i = 0; i < n; i++)
            board.push_back(row);
        return board;
    }

    bool canPlace(vector<string> &board, int x, int y)
    {
        int n = board.size();
        // row and col check; skip where we want to place
        for (int i = 0; i < n; i++)
        {
            if (board[i][y] == 'Q' and i != x)
                return false;
            if (board[x][i] == 'Q' and i != y)
                return false;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // skip where we want to place
                if (i == x and j == y)
                    continue;
                // if queen found, check if falls in diagonals
                if (board[i][j] == 'Q' && (i + j == x + y || i - j == x - y))
                    return false;
            }
        }
        // passed checks; can place
        return true;
    }

    vector<string> board;
    void solve(vector<string> &board, int y = 0)
    {
        int n = board.size();
        if (y == n)
        {
            solutions.push_back(board);
            return;
        }
        for (int x = 0; x < n; x++)
        {
            bool check = canPlace(board, x, y);
            if (check)
            {
                board[x][y] = 'Q';
                solve(board, y + 1);
                board[x][y] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        board = makeBoard(n);
        solve(board);
        return solutions;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution S;
    auto res = S.solveNQueens(5);
    for (auto board : res)
    {
        for (auto row : board)
        {
            cout << row << "\n";
        }
        cout << "\n";
    }
    return 0;
}
