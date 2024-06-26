class Solution {
private:
int solve(int amount , vector<int> &coin , int index){
    int n = coin.size();
    vector<vector<int>> dp(amount+1,vector<int> (n,0));
    for(int i=0 ; i<n ; i++){
        dp[0][i]=1;
    }
    for(int temp=1 ; temp<=amount ; temp++){
        for(int index=0 ; index<n ; index++){
            int ans =0;
            for(int i=index ; i<n ; i++){
                if(temp-coin[i]>=0){
                    ans = ans + dp[temp-coin[i]][i];
                }
            }
            dp[temp][index]=ans;
        }
    }
    return dp[amount][0];
}
public:
    int change(int amount, vector<int>& coins) {
        return solve(amount , coins , 0);
    }
};