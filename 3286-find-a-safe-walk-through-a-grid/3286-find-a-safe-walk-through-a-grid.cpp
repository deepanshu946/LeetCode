class Solution {
private:
bool solve(int i , int j ,vector<vector<int>>& grid, int n , int m , int health,vector<vector<bool>> &vis ,vector<vector<vector<int>>>& dp){

    if(health<=0){
        return false;
    }
    if(i==n-1 && j==m-1){
        return true;
    }
    if(dp[health][i][j] != -1){
        return dp[health][i][j];
    }
    vis[i][j]=1;
    bool ans = 0;
    if(i+1<n && !vis[i+1][j]){
        if(grid[i+1][j]==1){
            ans = ans | solve(i+1,j,grid,n,m,health-1,vis,dp);
        }
        else{
            ans = ans | solve(i+1,j,grid,n,m,health,vis,dp);
        }
    }
    if(j+1<m && !vis[i][j+1]){
        if(grid[i][j+1]==1){
            ans = ans | solve(i,j+1,grid,n,m,health-1,vis,dp);
        }
        else{
            ans = ans | solve(i,j+1,grid,n,m,health,vis,dp);
        }
    }
    if(i-1>=0 && !vis[i-1][j]){
        if(grid[i-1][j]==1){
            ans = ans | solve(i-1,j,grid,n,m,health-1,vis,dp);
        }
        else{
            ans = ans | solve(i-1,j,grid,n,m,health,vis,dp);
        }
    }
    if(j-1>=0 && !vis[i][j-1]){
        if(grid[i][j-1]==1){
            ans = ans | solve(i,j-1,grid,n,m,health-1,vis,dp);
        }
        else{
            ans = ans | solve(i,j-1,grid,n,m,health,vis,dp);
        }
    }
    vis[i][j]=0;
    return dp[health][i][j]= ans;



}
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        if(grid[0][0]==1){
            health=health-1;
        }
        vector<vector<bool>> vis(grid.size()+1,vector<bool>(grid[0].size()+1,0));
        vector<vector<vector<int>>> dp(health+1,vector<vector<int>>(grid.size()+1,vector<int>(grid[0].size()+1,-1)));

        return solve(0,0,grid,grid.size(),grid[0].size(),health,vis,dp);
    }
};