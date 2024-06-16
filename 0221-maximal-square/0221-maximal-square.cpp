class Solution {
private:
int solve(vector<vector<char>> &matrix , int i , int j , int &maxi,vector<vector<int>> &dp){
    if(i>=matrix.size() || j>=matrix[0].size()){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int right = solve(matrix , i , j+1 , maxi,dp);
    int dia = solve(matrix , i+1 , j+1 , maxi,dp);
    int down = solve(matrix , i+1 , j , maxi,dp);
    if(matrix[i][j]=='1'){
        dp[i][j] = 1 + min(right,min(dia,down));
        maxi = max(dp[i][j],maxi);
        // dp[i][j]=ans;
        return dp[i][j];
    }
    else{
        dp[i][j]=0;
        return dp[i][j];
    }
}
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        solve(matrix , 0 , 0 , maxi,dp);
        return maxi*maxi ;
    }
};