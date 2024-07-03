class Solution {
private:
//recursion
int solve( vector<int> prices , int n){
    // vector<vector<int>> dp(n+2 , vector<int> ( 2 , 0));
    vector<int> next1(2,0);
    vector<int> next2(2,0);
    vector<int> curr(2,0);
    // if(i>=n){
    //     return 0;
    // }
    for(int i=n-1 ; i>=0 ; i--){
        for(int buy=0 ; buy<=1 ; buy++){
            int profit = 0;
            if(buy){
                profit=max(-prices[i]+next1[0] , next1[1]);
            }
            else{
                profit = max(prices[i]+next2[1],next1[0]);
            }
            curr[buy]= profit;
        }
        next2 = next1;
        next1 = curr;
    }
    return next1[1];
}
public:
    int maxProfit(vector<int>& prices) {
        return solve(prices,prices.size());
    }
};