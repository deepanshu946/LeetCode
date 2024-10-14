class Solution {
private:
int solve(int i , int j , vector<vector<int>> &grid , int n ,int maxi  ,  vector<vector<bool>> &vis, vector<vector<vector<int>>> &dp){
    if(i<0 || j<0 || i>=n || j>=n){
        return INT_MAX;
    }
    if(i==n-1 && j==n-1){
        return max(maxi , grid[i][j]);
    }
    if(dp[i][j][maxi] != -1){
        return dp[i][j][maxi];
    }
    vis[i][j]=1;
    int ans = INT_MAX;
    maxi = max(maxi , grid[i][j]);
    if(i-1>=0 && !vis[i-1][j]){
        ans = min(ans , solve(i-1,j,grid,n,maxi,vis,dp));
    }
    if(j-1>=0 && !vis[i][j-1]){
        ans = min(ans , solve(i,j-1,grid , n,maxi,vis,dp));
    }
    if(i+1<n && !vis[i+1][j]){
        ans = min(ans , solve(i+1,j,grid , n,maxi,vis,dp));
    }
    if(j+1<n && !vis[i][j+1]){
        ans = min(ans , solve(i,j+1,grid , n,maxi,vis,dp));
    }
    vis[i][j]=0;
    return dp[i][j][maxi]= ans;
}
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n= grid.size();
        int ans = 0;
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        int temp =( n*n) + 1;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(temp,-1)));
        return max(grid[0][0],solve(0,0,grid,n,0,vis,dp)); 
    }
};