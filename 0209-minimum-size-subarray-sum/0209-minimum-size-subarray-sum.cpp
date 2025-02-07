class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int right = 0;
        int left = 0;
        int sum = 0;
        while(right<nums.size()){
            sum = sum + nums[right];
            if(sum>=target){
                ans = min(ans , right-left+1);
            }
            while(sum>=target){
                ans = min(ans, right-left+1);
                sum = sum - nums[left];
                left++;
            }
            right++;

        }
        if(ans == INT_MAX){
            return 0;
        }
        return ans;
    }
};