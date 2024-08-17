class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> results(n - k + 1);
        vector<int> dp(n, 0);
        deque<int> deque;

        // Step 1: Compute the DP array to check for consecutive sequences
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] == 1) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = 0;
            }
        }

        // Step 2: Use a sliding window approach to compute results
        for (int i = 0; i < n; i++) {
            // Maintain deque for the maximum element in the current window
            while (!deque.empty() && deque.front() < i - k + 1) {
                deque.pop_front();
            }

            while (!deque.empty() && nums[deque.back()] <= nums[i]) {
                deque.pop_back();
            }

            deque.push_back(i);

            // When we've filled the window
            if (i >= k - 1) {
                // Check if the subarray [i - k + 1, i] is valid (consecutive and sorted)
                if (dp[i] >= k - 1) {
                    results[i - k + 1] = nums[deque.front()];
                } else {
                    results[i - k + 1] = -1;
                }
            }
        }

        return results;
    }

};