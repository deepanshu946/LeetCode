class Solution {
private:
bool solve(int i , int j , vector<vector<int>> &grid , vector<vector<bool>> &vis, int m , int n){
   if(i>=m || i<0 || j>=n || j<0){
    return 0;
   }
   if(grid[i][j]==1){
    return 1;
   }
   vis[i][j]=1;
   bool ans = 1;
   if(i==m-1 || i==0 || j==0 || j==n-1){
    ans=0;
   }
   if(i+1<m && !vis[i+1][j]){
    ans = ans & solve(i+1,j,grid,vis,m,n);
   }
   if(j+1<n && !vis[i][j+1]){
    ans = ans & solve(i,j+1,grid,vis,m,n);
   }
   if(i-1>=0 && !vis[i-1][j]){
    ans = ans & solve(i-1,j,grid,vis,m,n);
   }
   if(j-1>=0 && !vis[i][j-1]){
    ans = ans & solve(i,j-1,grid,vis,m,n);
   }
   return ans;

}
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(m , vector<bool>(n , 0));
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(vis[i][j] == 0 && grid[i][j]==0){
                    bool temp = solve(i,j,grid,vis,m,n);
                    if(temp){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};