class Solution {
private:
int solve(vector<int> prices , int n , int k){
    vector<vector<int>> curr(2,vector<int>(k+1,0));
    vector<vector<int>> prev(2,vector<int>(k+1,0));

    for(int i=n-1 ; i>=0 ; i--){
        for(int buy=0 ; buy<=1 ; buy++){
            for(int limit =1 ; limit<=k ; limit++){
                int profit = 0; 
                if(buy){
                    profit=max(-prices[i]+prev[0][limit] , prev[1][limit]);
                }
                else{
                    profit = max(prices[i]+prev[1][limit-1],prev[0][limit]);
                }
                curr[buy][limit]=profit;
            }
        }
        prev=curr;
    }
    return prev[1][k];
    
}

public:
    int maxProfit(int k, vector<int>& prices) {
        return solve(prices,prices.size() , k);
    }
};