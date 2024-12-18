class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans = prices;
        stack<int> s;
        for(int i=prices.size()-1 ; i>=0 ; i--){
            while(!s.empty() && s.top() > prices[i]){
                s.pop();
            }
            if(!s.empty()){
                ans[i]=ans[i]-s.top();
            }
            s.push(prices[i]);
        }
        return ans;
    }
};