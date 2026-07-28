class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // vector<vector<int>> down(m,vector<int>(n,0));
        // vector<vector<int>> right(m,vector<int>(n,0));
        for(int i=m-1 ; i>=0 ; i--){
            for(int j=n-1 ; j>=0 ; j--){
                int down = 1e9;
                int right = 1e9;
                int dia = 1e9;

                if(matrix[i][j]==1){
                    if(i+1 <= m ){
                        down = dp[i+1][j];
                    }
                    if(j+1 <= n ){
                        right = dp[i][j+1];
                    }
                    if(i+1<=m && j+1<=n){
                        dia = dp[i+1][j+1];
                    }
                    dp[i][j]=1+min(down,min(right,dia));
                    ans+=dp[i][j];
                }
            }
        }
        return ans;





    }
};