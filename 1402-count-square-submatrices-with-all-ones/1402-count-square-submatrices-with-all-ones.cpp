class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        int left = 0;
        int down = 0;
        int dia = 0;
        int ans = 0;
        for(int i=m-1 ; i>=0 ; i--){
            for(int j=n-1 ; j>=0 ; j--){
                if(matrix[i][j]==1){
                    if(i+1 >= m || j+1 >= n){
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j]=1+min(dp[i+1][j],min(dp[i+1][j+1],dp[i][j+1]));
                    }
                }
                ans = ans + dp[i][j];
            }
        }
        return ans;
    }
};