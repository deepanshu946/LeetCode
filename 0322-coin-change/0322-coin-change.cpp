class Solution {
private:
int solve(vector<int> &coins , int amount , int n){
    vector<int> dp(amount+1 , INT_MAX);
    // if(amount<0){
    //     return INT_MAX;
    // }
    // if(amount==0){
    //     return 0;
    // }
    dp[0]=0;
    for(int i=1 ; i<=amount ; i++){
        int mini = INT_MAX;
        int ans;

        for(int j=n-1 ; j>=0 ; j--){
            if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX)
                dp[i]=min(dp[i],1+dp[i-coins[j]]);
        }
    }
    return dp[amount];
}
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = solve(coins,amount,n);
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};