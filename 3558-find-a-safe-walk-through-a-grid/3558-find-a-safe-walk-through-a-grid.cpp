class Solution {
private:
bool solve(int i , int j , vector<vector<int>> &grid , vector<vector<bool>> &vis , int m , int n , int health ,vector<vector<vector<int>>>& dp ){
    if(i==m-1 && j==n-1 ){
        if(grid[m-1][n-1]==0 && health>=1){
            return 1;
        }
        else if(grid[i][j]==1 && health>1){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(i<0 || j<0 || i>=m || j>=n){
        return 0;
    }
    if(health==0){
        return 0;
    }
    if(dp[health][i][j] != -1){
        return dp[health][i][j];
    }
    vis[i][j]=1;
   bool ans = 0; 
    if(!vis[i][j+1] ){
        ans = ans | solve(i,j+1,grid,vis,m,n,health-grid[i][j],dp);
    }
    if(!vis[i+1][j] ){
        ans = ans | solve(i+1,j,grid,vis,m,n,health-grid[i][j],dp);
    }
    if(j-1>=0 && !vis[i][j-1] ){
        ans = ans | solve(i,j-1,grid,vis,m,n,health-grid[i][j],dp);
    }
    if(i-1>=0 && !vis[i-1][j] ){
        ans = ans | solve(i-1,j,grid,vis,m,n,health-grid[i][j],dp);
    }
    vis[i][j]=0;
    return dp[health][i][j]= ans;
}
public:

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m+1,vector<bool>(n+1,0));
        vector<vector<vector<int>>> dp(health+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(0,0,grid,vis,m,n,health,dp);
    }
};