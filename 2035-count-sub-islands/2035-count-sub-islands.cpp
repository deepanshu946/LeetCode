class Solution {
private:
void markall(int i , int j , vector<vector<bool>> &vis , vector<vector<int>> &grid , int m , int n ){
    if(grid[i][j]==0){
        return;
    }
    vis[i][j]=1;
    if( i+1 < m && !vis[i+1][j]){
        markall(i+1,j,vis,grid,m,n);
    }
    if(j-1 >=0 && !vis[i][j-1]  ){
         markall(i,j-1,vis,grid,m,n);
    }
    if( i-1>=0 && !vis[i-1][j]  ){
        markall(i-1,j,vis,grid,m,n);
    }
    if(j+1 <n && !vis[i][j+1] ){
        markall(i,j+1,vis,grid,m,n);
    }
}
bool solve(int i , int j , vector<vector<bool>> &vis , vector<vector<int>>& grid1, vector<vector<int>>& grid2 , int m , int n){
    vis[i][j]=1;
    if(grid1[i][j] == 0  && grid2[i][j]==1){
        markall(i,j,vis,grid2,m,n);
        return false;
    }
    if( grid2[i][j]==0 ){
        return true;
    }
    
    bool ans = 1;
    if( i+1 < m && !vis[i+1][j]){
        ans = ans & solve(i+1,j,vis,grid1,grid2,m,n);
    }
    if(j-1 >=0 && !vis[i][j-1]  ){
        ans = ans & solve(i,j-1,vis,grid1,grid2,m,n);
    }
    if( i-1>=0 && !vis[i-1][j]  ){
        ans = ans & solve(i-1,j,vis,grid1,grid2,m,n);
    }
    if(j+1 <n && !vis[i][j+1] ){
        ans = ans & solve(i,j+1,vis,grid1,grid2,m,n);
    }
    return ans;

}
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int ans = 0;
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(!vis[i][j] && grid2[i][j]==1){
                    bool temp = solve(i,j,vis,grid1,grid2,m,n);
                    if(temp){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};