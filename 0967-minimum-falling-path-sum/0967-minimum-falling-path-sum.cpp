class Solution {
private:
int solve(int row , int col ,vector<vector<int>>& matrix , int n , int m  ){
    
    if(row<0 || row>=n){
        return INT_MAX;
    }
    if(col<0 || col>=m){
        return INT_MAX;
    }

    int left = solve(row+1,col-1 , matrix,n,m);
    int down = solve(row+1,col,matrix,n,m);
    int right = solve(row+1,col+1,matrix,n,m);

    if(left==INT_MAX && down==INT_MAX && right==INT_MAX){
        return matrix[row][col];
    }
    else{
        return matrix[row][col]+min(left,min(right,down));
    }
    
}
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = INT_MAX;
        //*recursion*
        // for(int i=0 ; i<n ; i++){
        //     ans = min(ans , solve(0,i,matrix,n,m ));
        // }
        // return ans;

        //*tabulation*
    //     vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX));
    //     for(int i=n-1 ; i>=0 ; i--){
    //     for(int j=m-1 ; j>=0 ; j--){
    //         int left = INT_MAX;
    //         if(j-1 >=0 )
    //             left = dp[i+1][j-1];
    //         int down = dp[i+1][j];
    //         int right = dp[i+1][j+1];

    //         if(left==INT_MAX && down==INT_MAX && right==INT_MAX){
    //             dp[i][j]=matrix[i][j];
    //         }
    //         else{
    //             dp[i][j]=matrix[i][j]+min(left,min(down,right));
    //         }
    //     }
    // }
    // for(int col=0 ; col<n ; col++){
    //         ans = min(ans,dp[0][col]);
    //     }
    //     return ans;

    //tabulation with space optimization
        // vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX));
        vector<int> curr(m+1,INT_MAX);
        vector<int> prev(m+1,INT_MAX);
        for(int i=n-1 ; i>=0 ; i--){
        for(int j=m-1 ; j>=0 ; j--){
            int left = INT_MAX;
            if(j-1 >=0 )
                left = prev[j-1];
            int down = prev[j];
            int right = prev[j+1];

            if(left==INT_MAX && down==INT_MAX && right==INT_MAX){
                curr[j]=matrix[i][j];
            }
            else{
                curr[j]=matrix[i][j]+min(left,min(down,right));
            }
        }
        prev = curr;
    }
        for(int col=0 ; col<n ; col++){
            ans = min(ans,prev[col]);
        }
        return ans;
    }
};