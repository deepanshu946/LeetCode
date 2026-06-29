class Solution {
private:
// int solve(int i, vector<int> &nums, int target, vector<int> &dp) {

//     if (i == nums.size() - 1) {
//         return 0;
//     }
//     if(dp[i] != -1){
//         return dp[i];
//     }
//     int ans = INT_MIN;
//     for (int j = i + 1; j < nums.size(); j++) {
//         if (abs(nums[i] - nums[j]) <= target) {
//             int temp = solve(j, nums, target,dp);
//             if (temp != INT_MIN) {
//                 ans = max(ans, 1 + temp);
//             }
//         }
//     }
//     return dp[i]= ans;

// }
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(),-1);
        dp[nums.size()-1]=0;
        for(int i=nums.size()-2 ; i>=0 ; i--){
            int ans = INT_MIN;
            for (int j = i + 1; j < nums.size(); j++) {
                if (abs(nums[i] - nums[j]) <= target) {
                    int temp = dp[j];
                    if (temp != INT_MIN) {
                        ans = max(ans, 1 + temp);
                    }
                }
            }
            dp[i]= ans;
        }
        return dp[0]==INT_MIN ? -1 :dp[0];



        // int ans = solve(0,nums,target,dp);
        // return ans==INT_MIN ? -1 :ans;
    }
};