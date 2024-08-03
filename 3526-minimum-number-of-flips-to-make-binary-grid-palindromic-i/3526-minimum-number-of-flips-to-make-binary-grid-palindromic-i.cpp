class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        // rows
        int rowans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            int start = 0;
            int end = n - 1;
            while (start < end) {
                if (grid[i][start] != grid[i][end]) {
                    rowans++;
                }
                start++;
                end--;
            }
        }
        int colans = 0;
        for (int i = 0; i < n; i++) {
            int start = 0;
            int end = m - 1;
            while (start < end) {
                if (grid[start][i] != grid[end][i]) {
                    colans++;
                }
                start++;
                end--;
            }
        }
        return min(rowans,colans);
    }
};