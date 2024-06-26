class Solution {
    int solve(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int> (2 ,0)));

        for(int start=n-1 ; start>=0 ; start--){
            for(int end =start+1 ; end<n ; end++ ){
                for(int alice=1 ; alice>=0; alice--){
                    int ans1 = INT_MIN;
                    int ans2 = INT_MIN;
                    if (alice) {
                        ans1 = piles[start] + dp[start+1][end][0];
                        ans2 = piles[end] + dp[start][end-1][0];

                    } else {
                        ans1 = dp[start+1][end][1];
                        ans2 = dp[start][end-1][1];
                    }
                    dp[start][end][alice] = max(ans1, ans2);
                }
            }
        }
        return dp[0][n-1][1];
    }

public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum = sum + piles[i];
        }
        int alice = solve(piles);
        if (alice > sum / 2) {
            return true;
        }
        return false;
    }
};


//rec + memo
int solver(vector<int>& piles, int start, int end, bool alice,vector<vector<vector<int>>> &dp) {
        if (start >= end) {
            return 0;
        }
        if(dp[start][end][alice] != -1){
            return dp[start][end][alice];
        }
        int ans1 = INT_MIN;
        int ans2 = INT_MIN;
        if (alice) {
            ans1 = piles[start] + solver(piles, start + 1, end, 0,dp);
        } else {
            ans1 = solver(piles, start + 1, end, 1,dp);
        }
        if (alice) {
            ans2 = piles[end] + solver(piles, start, end - 1, 0,dp);
        } else {
            ans2 = solver(piles, start, end - 1, 1,dp);
        }

        dp[start][end][alice] = max(ans1, ans2);
        return dp[start][end][alice];
    }