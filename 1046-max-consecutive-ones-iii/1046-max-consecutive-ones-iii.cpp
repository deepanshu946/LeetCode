class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int ans =0;
        int n = nums.size();
        int zero = 0;
        while(right<n){
            if(nums[right]==0){
                zero++;
            }
            if(zero<=k){
                ans = max(ans , right-left+1);
            }
            else{
                while(zero>k && left<right){
                    if(nums[left]==0){
                        zero--;
                    }
                    left++;
                }
            }
            right++;
        }
        return ans;
    }
};