class Solution {
private:
int solve(int m , int n){
    vector<vector<int>> dp(m+1 , vector<int>(n+1 , 0));
    // if(i==m-1 && j==n-1){
    //     return 1;
    // }
    dp[m-1][n-1]=1;
    // int right = solve(i,j+1,m,n,dp);
    // int down = solve(i+1,j,m,n,dp);
    // dp[i][j]=right + down;
    // return dp[i][j];
    for(int i=m-1; i>=0 ; i--){
        for(int j=n-1;j>=0 ; j--){
            int right = dp[i][j+1];
            int down = dp[i+1][j];
            if(i == m-1 && j == n-1){

            }
            else{
                dp[i][j]=right + down;
            }
                
            cout<<dp[i][j]<<endl;
        }
    }
    return dp[0][0];
}
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m , vector<int> ( n , -1));
        return solve(m , n);
    }
};