class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int right = 1;
        int ans = 0;
        int zero=0;
        if(nums[left]==0){
            zero++;
        }
        while(right<nums.size() && left<nums.size()){
            if(nums[right]==0){
                zero++;
            }
            if(zero<=1){
                ans=max(ans,right-left);
                
                right++;
            }
            else{
                if(nums[left]==0){
                    zero--;
                }
                left++;
                right++;
            }
        }
        return ans;
    }
};