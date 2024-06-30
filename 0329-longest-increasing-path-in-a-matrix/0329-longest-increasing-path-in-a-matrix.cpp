class Solution {
private:
int solve(vector<vector<int>> &matrix , int i , int j , int m , int n , vector<vector<int>> &dp){
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int ans =1;
    if(j+1<n && matrix[i][j+1] > matrix[i][j]){
        ans = max(ans,solve(matrix,i,j+1,m,n,dp) + 1);
    }
    if(i+1<m && matrix[i+1][j] > matrix[i][j]){
        ans = max(ans,solve(matrix,i+1,j,m,n,dp) + 1);
    }
    if(j-1>=0 && matrix[i][j-1] > matrix[i][j]){
        ans = max(ans,solve(matrix,i,j-1,m,n,dp) + 1);
    }
    if(i-1>=0 && matrix[i-1][j] > matrix[i][j]){
        ans = max(ans,solve(matrix,i-1,j,m,n,dp) + 1);
    }
    return dp[i][j] = ans;

}
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans =0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        for(int i=0 ; i<m ;i++){
            for(int j=0 ; j<n ; j++){
                ans = max(ans , solve(matrix , i , j , m ,n,dp));
            }
        }
        return ans;
    }
};