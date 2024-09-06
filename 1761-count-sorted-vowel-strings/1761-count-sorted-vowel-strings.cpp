class Solution {
private:
int solve(int count , int prev , int n , vector<vector<int>> &dp){
    if(count==n){
        return 1;
    }
    if(dp[count][prev] != -1){
        return dp[count][prev];
    }
    int ans = 0;
    for(int i=prev ; i<5 ; i++){
        ans = ans + solve(count+1,i,n,dp);
    }
    return dp[count][prev]= ans;
}
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1, vector<int>(5,-1));
        return solve(0,0,n,dp);
    }
};