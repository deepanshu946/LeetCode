class Solution {
private:
void solve(int i , int j , vector<vector<int>> &grid, int &ans ,int m , int n , vector<vector<bool>> &vis,int &count,int left){
    
    if(i>=m || i<0 || j>=n || j<0){
        return;
    }
    if(grid[i][j]==2){
        if(count-1==left){
            ans++;
        }
        return;
    } 
    if(grid[i][j]==-1){
        return ;
    }
    vis[i][j]=1;
    count++;
    if(i+1<m && !vis[i+1][j] ){
        solve(i+1,j,grid,ans,m,n,vis,count,left);
    }
    if(j+1<n && !vis[i][j+1] ){
        solve(i,j+1,grid,ans,m,n,vis,count,left);
    }
    if(i-1>=0 && !vis[i-1][j] ){
        solve(i-1,j,grid,ans,m,n,vis,count,left);
    }
    if(j-1>=0 && !vis[i][j-1] ){
        solve(i,j-1,grid,ans,m,n,vis,count,left);
    }
    vis[i][j]=0;
    count--;
}
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        int r;
        int c;
        int temp=0;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j]==1){
                    r=i;
                    c=j;
                }
                if(grid[i][j]==0){
                    temp++;
                }
            }
        }
        int count = 0;
        solve(r,c,grid,ans,m,n,vis,count,temp);
        return ans;
    }
};