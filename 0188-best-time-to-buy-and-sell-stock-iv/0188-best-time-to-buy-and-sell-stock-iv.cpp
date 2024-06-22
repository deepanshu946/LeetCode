class Solution {
private:
int solve( int k , vector<int> &prices , int n){
    // vector<vector<int>> dp(n+1,vector<int>((2*k)+1,0));
    vector<int> curr((2*k)+1 , 0);
    vector<int> prev((2*k)+1 , 0);



    for(int i=n-1 ; i>=0 ; i--){
        for(int op=(2*k)-1 ; op>=0 ; op--){
            int profit = 0;
            if(op%2==0){
                //buy
                profit = max(-prices[i]+prev[op+1],prev[op]);
            }
            else{
                profit = max(prices[i]+prev[op+1] , prev[op]);
            }
            curr[op]=profit;
        }
        prev = curr;
    }
    return prev[0];
}

public:
    int maxProfit(int k, vector<int>& prices) {
        return solve(k,prices,prices.size());
    }
};



//same spproach as 3 part
int solvetab(vector<int> prices , int n , int k){
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