class Solution {
private:
int solve(vector<int> &prices , int n){
    // vector<vector<int>> dp(n+1,vector<int>(2,0));
    vector<int> curr(2,0);
    vector<int> prev(2,0);
    for(int i=n-1 ; i>=0 ; i--){
        for(int buy = 0 ; buy<=1 ; buy++){
            int profit = 0;
            if(buy){
                profit=max(-prices[i]+prev[0] , prev[1]);
            }
            else{
                profit = max(prices[i]+prev[1],prev[0]);
            }
            curr[buy]=profit;
        }
        prev = curr;
    }
    return prev[1];
}
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return solve(prices,n);
    }
};