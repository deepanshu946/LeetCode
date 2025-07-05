class Solution {
private:
long long solve(int i , int j , int sec , int m , int n , vector<vector<int>> &nums , vector<vector<vector<long long>>> &dp){
    if(i>=m || j>=n ){
        return LLONG_MAX;
    }
    if(i==m-1 && j==n-1){
        return (i+1)*(j+1);
    }
    if(dp[i][j][sec] != -1){
        return dp[i][j][sec];
    }
    if(sec==1){
        return dp[i][j][sec]= nums[i][j]+solve(i,j,0,m,n,nums,dp);
    }
    else{
        return dp[i][j][sec]= (i+1)*(j+1) + min(solve(i+1,j,1,m,n,nums,dp) , solve(i,j+1,1,m,n,nums,dp) );
    }
    return dp[i][j][sec]= 0;
}
public:
    long long minCost(int m, int n, vector<vector<int>>& nums) {
        vector<vector<vector<long long>>> dp(m+1,vector<vector<long long>>(n+1,vector<long long>(2,-1)));
        return solve(0,0,0,m,n,nums,dp);

        // dp[m-1][n-1][0]=(m)*(n);
        // dp[m-1][n-1][1]=(m)*(n);

        // for(int i=m-2; i>=0 ; i--){
        //     for(int j=n-2 ; j>=0 ; j--){
        //         for(int sec = 1 ; sec>=0 ; sec--){
        //             // if(i>=m || j>=n ){
        //             //     return 1e9;
        //             // }
        //             // if(i==m-1 && j==n-1){
        //             //     return (i+1)*(j+1);
        //             // }
        //             if(sec){
        //                 dp[i][j][sec]= nums[i][j]+dp[i][j][!sec]; 
        //             }
        //             else{
        //                 dp[i][j][sec]= (i+1)*(j+1) + min(dp[i+1][j][!sec] , dp[i][j+1][!sec] );
        //             }
        //         }
        //     }
        // }
        // return dp[0][0][0];

    }
};