class Solution {
private:
int solve(int i , int j , int m , int n , vector<vector<int>> &grid , vector<vector<bool>> &vis){
    if(i>=m || j>=n || i<0 || j<0){
        return 0;
    }
    if(grid[i][j]==0){
        return 0;
    }
    vis[i][j]=1;
    int ans = 0;
    if(!vis[i][j+1]){
        ans = max(ans , grid[i][j]+solve(i,j+1,m,n,grid,vis));
    }
    if(!vis[i+1][j]){
        ans = max(ans , grid[i][j]+solve(i+1,j,m,n,grid,vis));
    }
    if(j-1>=0 && !vis[i][j-1]){
        ans = max(ans , grid[i][j]+solve(i,j-1,m,n,grid,vis));
    }
    if(i-1>=0 && !vis[i-1][j]){
        ans = max(ans , grid[i][j]+solve(i-1,j,m,n,grid,vis));
    }
    vis[i][j]=0;
    return ans;
}
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(m+1,vector<bool>(n+1,0));
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] != 0){
                    ans = max(ans , solve(i,j,m,n,grid,vis));
                }
            }
        }
        return ans;
    }
};