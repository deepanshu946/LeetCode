class Solution {
    int solve(vector<int>& piles, int start, int end, bool alice,vector<vector<vector<int>>> &dp) {
        if (start >= end) {
            return 0;
        }
        if(dp[start][end][alice] != -1){
            return dp[start][end][alice];
        }
        int ans1 = INT_MIN;
        int ans2 = INT_MIN;
        if (alice) {
            ans1 = piles[start] + solve(piles, start + 1, end, 0,dp);
        } else {
            ans1 = solve(piles, start + 1, end, 1,dp);
        }
        if (alice) {
            ans2 = piles[end] + solve(piles, start, end - 1, 0,dp);
        } else {
            ans2 = solve(piles, start, end - 1, 1,dp);
        }

        dp[start][end][alice] = max(ans1, ans2);
        return dp[start][end][alice];
    }

public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(n+1 , vector<int> ( 2 ,-1)));

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum = sum + piles[i];
        }
        int alice = solve(piles, 0, n - 1, 1,dp);
        if (alice > sum / 2) {
            return true;
        }
        return false;
    }
};