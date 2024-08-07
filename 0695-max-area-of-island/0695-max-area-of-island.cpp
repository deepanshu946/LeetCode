class Solution {
private:
int solve(vector<vector<int>> &grid , vector<vector<int>> &vis , int i , int j , int m , int n){
    if(i>=m || j>=n ){
        return 0;
    }
    if(grid[i][j]==0){
        return 0;
    }
    vis[i][j]=1;
    int area = 0;
    if(j+1<n && vis[i][j+1] == 0 ){
        area = area + solve(grid,vis,i,j+1,m,n);
    }
    if(i+1<m && vis[i+1][j] == 0 ){
        area = area + solve(grid,vis,i+1,j,m,n);
    }
    if(j-1>=0 && vis[i][j-1] == 0 ){
        area = area + solve(grid,vis,i,j-1,m,n);
    }
    if(i-1 >=0 && vis[i-1][j] == 0 ){
        area = area + solve(grid,vis,i-1,j,m,n);
    }
    return area+1;


}
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(vis[i][j] == 0 && grid[i][j]==1){
                    ans = max(ans , solve(grid,vis,i,j,m,n));
                }
            }
        }
        return ans;
    }
};