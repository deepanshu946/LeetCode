class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int n = prices.size();
        int ans = INT_MIN;
        for(int i=1 ; i<n ; i++){
            int val = prices[i]-min;
            ans = max(ans , val);
            if(prices[i]<min){
                min = prices[i];
            }
        }
        if(ans<0){
            return 0;
        }
        return ans;
    }
};