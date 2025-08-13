class Solution {
private:
void solve(int i , int j , vector<vector<char>> &grid , vector<vector<bool>> &vis, int n , int m){
    if(i>=n || j>=m || i<0 || j<0){
        return;
    }
    if(grid[i][j] == '0'){
        return;
    }
    if(vis[i][j]==1){
        return;
    }
    vis[i][j]=1;
    if(i+1<n && !vis[i+1][j]){
        solve(i+1,j,grid,vis,n,m);
    }
    if(j+1<m && !vis[i][j+1]){
        solve(i,j+1,grid,vis,n,m);
    }
    if(i-1>=0 && !vis[i-1][j]){
        solve(i-1,j,grid,vis,n,m);
    }
    if(j-1>=0 && !vis[i][j-1]){
        solve(i,j-1,grid,vis,n,m);
    }
}
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    solve(i,j,grid,vis,n,m);
                    count++;
                }
            }
        }
        return count;

    }
};