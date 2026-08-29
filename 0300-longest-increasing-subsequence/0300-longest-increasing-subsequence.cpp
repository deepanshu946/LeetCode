class Solution {
public:
    int lengthOfLIS(vector<int>& A) {
         int n = A.size();
    // return solve(0,A,A.size(),0);
    vector<vector<int>> dp(n+1 , vector<int>(n+1,0));
    for(int i=n-1 ; i>=0 ; i--){
        for(int prev = n ; prev >=0 ; prev--){
            int inc=0;
            if( prev-1 == -1 || A[i]>A[prev-1]){
                inc = 1 + dp[i+1][i+1];
            }
            int exc =dp[i+1][prev];
            dp[i][prev]= max(inc , exc);
        }
    }
    // cout<<dp[0][0]<<endl;
    return dp[0][0];
    }
};