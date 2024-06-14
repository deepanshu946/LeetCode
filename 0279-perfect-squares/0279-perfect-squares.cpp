class Solution {
private:
int solve(int n){
    vector<int> dp(n+1 , INT_MAX);
    dp[0]=0;
    // if(dp[n] != -1){
    //     return dp[n];
    // }
    int ans = INT_MAX;
    // for(int i=1 ; i<=sqrt(n) ; i++){
    //    int val = solve(n-(i*i),dp);
    //     ans = min(ans,1+val);
    // }
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=sqrt(i) ; j++){
            int val = dp[i-(j*j)];
            dp[i]=min(dp[i],val+1);
        }
    }
    return dp[n];
}
public:
    int numSquares(int n) {
        return solve(n);
    }
};