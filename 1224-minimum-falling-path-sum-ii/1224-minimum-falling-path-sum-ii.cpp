class Solution {
private:
int solve(int i , int prev , vector<vector<int>> &grid , int m , int n , vector<vector<int>> &dp){
    if(i==m){
        return 0;
    }
    if(dp[i][prev] != -1){
        return dp[i][prev];
    }
    int ans = 1e9;
    for(int col = 0 ; col<n ; col++){
        if(prev == col){
            continue;
        }
        ans = min(ans,grid[i][col]+solve(i+1,col,grid,m,n,dp));
    }
    return dp[i][prev]=ans;
}
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 1e9;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        if(m==1 && n==1){
            return grid[0][0];
        }
        for(int j=0 ; j<n ; j++){
            ans = min(ans , solve(0,j,grid,m,n,dp)) ;
        }
        return ans;
    }
};