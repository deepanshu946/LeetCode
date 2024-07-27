class Solution {
private:
    void solve(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& dp,
               int m, int n) {
        if (i >= m || i < 0 || j >= n || j < 0) {
            return;
        }
        if (dp[i][j]) {
            return;
        }
        dp[i][j] = 1;
        if (j + 1 < n && grid[i][j + 1] >= grid[i][j]) {
            solve(i, j + 1, grid, dp, m, n);
        }
        if (i + 1 < m && grid[i + 1][j] >= grid[i][j]) {
            solve(i+1, j, grid, dp, m, n);
        }
        if (j - 1 >= 0 && grid[i][j - 1] >= grid[i][j]) {
            solve(i, j - 1, grid, dp, m, n);
        }
        if (i - 1 >= 0 && grid[i - 1][j] >= grid[i][j]) {
            solve(i-1, j , grid, dp, m, n);
        }

    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, 0));
        vector<vector<bool>> atlantic(m, vector<bool>(n, 0));
        for (int i = 0; i < m; i++) {
            solve(i, 0, board, pacific, m, n);
            solve(i, n - 1, board, atlantic, m, n);
        }
        for (int j = 0; j < n; j++) {
            solve(0, j, board, pacific, m, n);
            solve(m - 1, j, board, atlantic, m, n);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j]&& atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};