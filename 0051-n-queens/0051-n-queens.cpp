
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;

    void solve(int col, int n, vector<string>& board,
               vector<int>& row, vector<int>& diagonal,
               vector<int>& antidiagonal)
    {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }

        for(int r = 0; r < n; r++)
        {
            if(row[r] == 0 &&
               diagonal[col+r] == 0 &&
               antidiagonal[n-1+col-r] == 0)
            {
                board[r][col] = 'Q';

                row[r] = 1;
                diagonal[col+r] = 1;
                antidiagonal[n-1+col-r] = 1;

                solve(col+1, n, board, row,
                      diagonal, antidiagonal);

                board[r][col] = '.';

                row[r] = 0;
                diagonal[col+r] = 0;
                antidiagonal[n-1+col-r] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        


        vector<string> board(n, string(n, '.'));
        vector<int> row(n, 0);
        vector<int> diagonal(2*n-1, 0);
        vector<int> antidiagonal(2*n-1, 0);

        solve(0, n, board, row, diagonal, antidiagonal);

        return ans;
    }
};
