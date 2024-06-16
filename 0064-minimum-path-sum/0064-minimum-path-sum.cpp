class Solution {
private:
int solve(vector<vector<int>> &matrix , int n , int m,int i, int j){
    vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX));
    
    dp[n-1][m-1]=matrix[n-1][m-1];

    for(int i=n-1 ; i>=0 ; i--){
        for(int j=m-1 ; j>=0 ; j--){
            int right = dp[i][j+1];
            int down = dp[i+1][j];
            if(i==n-1 && j==m-1){
                continue;
            }
            else{
                dp[i][j]=matrix[i][j]+min(right,down);
            }
            // return matrix[i][j]+min(right,down);
        }
    }
    return dp[0][0];
    
}
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        return solve(grid,n,m,0,0);
    }
};