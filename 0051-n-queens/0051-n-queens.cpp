// #include<string>

class Solution {
private:
    bool issafe(int row, int col, vector<string> &board, int n) {
        // for row
        int x = row;
        int y = col;
        while (y >= 0) {
            if (board[x][y] == 'Q') {
                return false;
                
            }
            y--;
        }
        // for upper diagonal
        x = row;
        y = col;
        while (x >= 0 && y >= 0) {
            if (board[x][y] == 'Q') {
                return false;
            }
            x--;
            y--;
        }
        // for lower diagonal
        x = row;
        y = col;
        while (x < n && y >= 0) {
            if (board[x][y] == 'Q') {
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
    void solve(int col, vector<vector<string>> &ans, vector<string> &board,
               int n) {
        // base case;
        if (col == n) {
            //push all the possible board in ans
            ans.push_back(board);
            return;
        }
        // just check for 1st column & rest will be done by recursion
        for (int row = 0; row < n; row++) {
            if (issafe(row, col, board, n)) {
                //insert queen
                board[row][col] = 'Q';
                solve(col + 1, ans, board, n);
                //backtracked and remove the queen
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        //initialize board with '.' 
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        solve(0, ans, board, n);
        return ans;
    }
};