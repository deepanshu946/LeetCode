class Solution {
private:
int solve(int n,int temp,vector<int> &dp){
    if(n<=0){
        return 1;
    }
    if(n==1){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int lim = n;
    if(n==temp){
        lim=n-1;
    }
    int ans = 0;
    for(int i=1 ; i<=lim ; i++){
        ans = max(ans , i * solve(n-i,temp,dp)); 
    }
    return dp[n]= ans;
}
public:
    int integerBreak(int n) {
        // int ans = 0;
        // for(int i=1 ; i<n ; i++){
        //     ans = max(ans , i*solve(n-i));
        // }
        vector<int> dp(n+1,-1);
        return solve(n,n,dp);
    }
};