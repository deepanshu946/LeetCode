class Solution {
private:
int solve(vector<int> &coins , int amount , int index){
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount+1,0));
    for(int i=0 ; i<n ; i++){
        dp[i][0]=1;
    }
    for(int index=0 ; index<n ; index++){
        for(int temp = 1 ; temp<=amount ; temp++){
             int take = 0;
             int val = temp-coins[index];
            if(val>=0){
                take=dp[index][val];
            }
            int nottake = 0;
            if(index-1>=0){
                nottake= dp[index-1][temp];
            }
            dp[index][temp] = take+nottake;
        }
    }
    return dp[n-1][amount];
   

}
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return solve(coins , amount , n-1);
    }
};