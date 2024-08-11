class Solution {
private:
void solve(int i , int j , vector<vector<char>> &grid , vector<vector<int>> &vis, int m , int n ){
    if(i>=m || j>=n || j<0 || i<0){
        return ;
    }
    if(grid[i][j]=='0'){
        return;
    }
    vis[i][j]=1;
    if(i+1<m && vis[i+1][j] == 0){
        solve(i+1,j,grid,vis,m,n);
    }
    if(j+1<n && vis[i][j+1] == 0){
        solve(i,j+1,grid,vis,m,n);
    }
    if(j-1>=0 && vis[i][j-1] == 0 ){
        solve(i,j-1,grid,vis,m,n);
    }
    if(i-1>=0 && vis[i-1][j] == 0){
        solve(i-1,j,grid,vis,m,n);
    }
    return ;
}
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans=0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    solve(i,j,grid,vis, m , n);
                    ans++;
                }
            }
        }
        return ans;
    }
};