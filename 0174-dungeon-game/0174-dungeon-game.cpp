class Solution {
private:
int solve(vector<vector<int>> &grid , int row , int col , int m , int n){
    vector<vector<int>> dp(m+1 , vector<int> ( n+1 , INT_MAX));
    // if(row>=m || col>=n){
    //     return INT_MAX;
    // }
    if(grid[m-1][n-1]<0){
            dp[m-1][n-1] = -(grid[m-1][n-1]-1);
        }
        else{
            dp[m-1][n-1]= 1;
        }

    for(int row=m-1 ; row>=0 ; row--){
        for(int col=n-1 ; col>=0 ; col--){
            if(row==m-1 && col==n-1){
                continue;
            }
            int right = dp[row][col+1];
            int down = dp[row+1][col];
            int val =min(right,down)-grid[row][col];
            if(val<=0){
                dp[row][col]= 1;
            }
            else{
                dp[row][col]= val;
            }
        }
    }
    return dp[0][0];
    
}

public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        return solve(dungeon , 0 , 0 , m , n);
    }
};