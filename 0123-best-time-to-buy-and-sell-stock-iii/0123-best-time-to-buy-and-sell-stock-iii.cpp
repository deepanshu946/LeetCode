class Solution {
private:
int solve(vector<int> prices , int n){
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    for(int i=n-1 ; i>=0 ; i--){
        for(int buy=0 ; buy<=1 ; buy++){
            for(int limit =1 ; limit<=2 ; limit++){
                int profit = 0; 
                if(buy){
                    profit=max(-prices[i]+dp[i+1][0][limit] , dp[i+1][1][limit]);
                }
                else{
                    profit = max(prices[i]+dp[i+1][1][limit-1],dp[i+1][0][limit]);
                }
                dp[i][buy][limit]=profit;
            }
        }
    }
    return dp[0][1][2];
    
}

public:
    int maxProfit(vector<int>& prices) {
        return solve(prices,prices.size());
    }
};



//recursion
int solverec(int i , bool buy , int limit , vector<int> prices , int n){
    if(i>=n || limit ==0 ){
        return 0;
    }
    int profit = 0;
    if(buy){
        profit=max(-prices[i]+solverec(i+1,0,limit ,prices,n) , solverec(i+1,1,limit , prices,n));
    }
    else{
        profit = max(prices[i]+solverec(i+1,1,limit-1,prices,n),solverec(i+1,0,limit,prices,n));
    }
    return profit;
}