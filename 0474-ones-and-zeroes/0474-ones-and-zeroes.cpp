class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // Initialize the dp array
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        // Preprocess the count of 0's and 1's in each string
        vector<pair<int, int>> count(strs.size());
        for (int i = 0; i < strs.size(); ++i) {
            int ones = 0, zeros = 0;
            for (char c : strs[i]) {
                if (c == '1') ones++;
                else zeros++;
            }
            count[i] = {ones, zeros};
        }

        // Fill the dp array
        for (int i = 1; i <= strs.size(); ++i) {
            int ones = count[i-1].first;
            int zeros = count[i-1].second;
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= n; ++k) {
                    if (j >= zeros && k >= ones) {
                        dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-zeros][k-ones] + 1);
                    } else {
                        dp[i][j][k] = dp[i-1][j][k];
                    }
                }
            }
        }

        return dp[strs.size()][m][n];
    }
};
