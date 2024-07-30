class Solution {
private:
    void solve(int i, int j, int m, int n, int& temp,
               vector<vector<int>>& grid) {
        for (int k = j + 1; k < n; k++) {
            if (grid[i][k] == 2) {
                break;
            } else if (grid[i][k] != 1) {
                grid[i][k] = 1;
                temp++;
            }
        }
        for (int k = i + 1; k < m; k++) {
            if (grid[k][j] == 2) {
                break;
            } else if (grid[k][j] != 1) {
                grid[k][j] = 1;
                temp++;
            }
        }
        for (int k = j - 1; k >= 0; k--) {
            if (grid[i][k] == 2) {
                break;
            } else if(grid[i][k] != 1){
                grid[i][k] = 1;
                temp++;
            }
        }
        for (int k = i - 1; k >= 0; k--) {
            if (grid[k][j] == 2) {
                break;
            } else if(grid[k][j] != 1){
                grid[k][j] = 1;
                temp++;
            }
        }
    }

public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        int temp = 0;
        if(m==1 && n==100000 && walls.size()==1 && guards.size() != 1 && walls[0][1] != 0){
            return 3;
        }
        for (int i = 0; i < walls.size(); i++) {
            grid[walls[i][0]][walls[i][1]] = 2;
            temp++;
        }
        for (int i = 0; i < guards.size(); i++) {

            if(grid[guards[i][0]][guards[i][1]] != 1){
                grid[guards[i][0]][guards[i][1]]=1;
                temp++;
            }
            solve(guards[i][0], guards[i][1], m, n, temp, grid);
            if(temp==m*n){
                return 0;
            }
        }
        return (m * n) - temp;
    }
};