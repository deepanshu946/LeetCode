class Solution {
private:
// int solve(int i , int j , int m , int n , vector<vector<int>> &grid , vector<vector<int>> &dp){
//     if(i>=m || j>=n){
//         return 0;
//     }
//     if(dp[i][j] != -1){
//         return dp[i][j];
//     }
//     int ans = 0;
//     if(i-1 >=0 && j+1<n && grid[i-1][j+1] > grid[i][j]){
//         ans = max(ans , 1+solve(i-1,j+1,m,n,grid,dp));
//     }
//     if(j+1<n && grid[i][j+1] > grid[i][j]){
//         ans = max(ans , 1+solve(i,j+1,m,n,grid,dp));
//     }
//     if(i+1<m && j+1<n && grid[i+1][j+1] > grid[i][j]){
//         ans = max(ans , 1+solve(i+1,j+1,m,n,grid,dp));
//     }
//     return dp[i][j]= ans;
// }
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        // vector<vector<int>> dp(m,vector<int>(n,0));
        // for(int i=0 ; i<m ; i++){
        //     ans = max(ans , solve(i,0,m,n,grid,dp));
        // }
        // return ans;
        vector<int> curr(m,0);
        vector<int> prev(m,0);

        for(int j=n-2 ; j>=0 ;j--){
            for(int i=0 ; i<m ; i++){
                int ans = 0;
                if(i-1 >=0 && j+1<n && grid[i-1][j+1] > grid[i][j]){
                    ans = max(ans , 1+curr[i-1]);
                }
                if(j+1<n && grid[i][j+1] > grid[i][j]){
                    ans = max(ans , 1+curr[i]);
                }
                if(i+1<m && j+1<n && grid[i+1][j+1] > grid[i][j]){
                    ans = max(ans , 1+curr[i+1]);
                }
                prev[i]= ans;
            }
            curr = prev;
        }
        for(int i=0 ; i<m ; i++){
            ans = max(ans , curr[i]);
        }
        return ans;

    }
};