class Solution {
private:
    long long solve(int m, int n, vector<vector<long long>>& dp, vector<vector<long long>>& pricesMap) {
        if (dp[m][n] != -1) {
            return dp[m][n];
        }

        long long maxProfit = pricesMap[m][n];
        
        for (int i = 1; i < m; ++i) {
            maxProfit = max(maxProfit, solve(i, n, dp, pricesMap) + solve(m - i, n, dp, pricesMap));
        }

        for (int j = 1; j < n; ++j) {
            maxProfit = max(maxProfit, solve(m, j, dp, pricesMap) + solve(m, n - j, dp, pricesMap));
        }

        dp[m][n] = maxProfit;
        return dp[m][n];
    }

public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, -1));
        vector<vector<long long>> pricesMap(m + 1, vector<long long>(n + 1, 0));

        for (auto& price : prices) {
            pricesMap[price[0]][price[1]] = price[2];
        }

        return solve(m, n, dp, pricesMap);
    }
};
