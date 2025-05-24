class Solution {
private:
void solve(int i , int j , vector<vector<int>> &check , vector<vector<int>> &grid , int n , int m){
    if(i>=n || j>=m || i<0 || j<0){
        return;
    }
    if(grid[i][j] == 0){
        return;
    }
    if(check[i][j]==1){
        return;
    }
    check[i][j]=1;
    solve(i+1,j,check,grid,n,m);
    solve(i-1,j,check,grid,n,m);
    solve(i,j+1,check,grid,n,m);
    solve(i,j-1,check,grid,n,m);

}
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> check(n , vector<int>(m,0));
        for(int i=0 ; i<n ; i++){
            solve(i,0,check,grid,n,m);
            solve(i,m-1,check,grid,n,m);
        }
        for(int j=0 ; j<m ; j++){
            solve(0,j,check,grid,n,m);
            solve(n-1,j,check,grid,n,m);
        }
        int ans = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(!check[i][j] && grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};