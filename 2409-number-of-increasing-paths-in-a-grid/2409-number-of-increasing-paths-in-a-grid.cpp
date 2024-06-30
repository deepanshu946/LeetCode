class Solution {
private:
#define mod 1000000007
int solve(vector<vector<int>> &grid , int i , int j , int m , int n,vector<vector<int>> &dp){
    if(dp[i][j] != -1){
        return (dp[i][j]);
    }
    int ans = 0;
    if(j+1<n && grid[i][j+1]>grid[i][j]){
        ans = ans + 1 + solve(grid,i,j+1,m,n,dp);
    }
     if(i+1<m && grid[i+1][j]>grid[i][j]){
        ans = ans + 1 + solve(grid,i+1,j,m,n,dp);
    }
     if(j-1>=0 && grid[i][j-1]>grid[i][j]){
        ans = ans + 1 + (solve(grid,i,j-1,m,n,dp))%mod;
    }
     if(i-1>=0 && grid[i-1][j]>grid[i][j]){
        ans = ans + 1 + (solve(grid,i-1,j,m,n,dp))%mod;
    }
    return dp[i][j]= ans%mod;

}
public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
         int n = grid[0].size();
         int ans =0;
         vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
         for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){

                ans = (1+ans+solve(grid,i,j,m,n,dp))%mod;
            }
         }
         return ans;
    }
};