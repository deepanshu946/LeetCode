class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int ans = 0;
        int ones = 0;
        int zeros=0;
        while(right<nums.size()){
            // if(nums[right]==1){
            //     ones++;
            // }
            if(nums[right]==0){
                zeros++;
                if(zeros > k){
                    while(zeros != k){
                        if(nums[left]==0){
                            zeros--;
                        }
                        else{
                            ones--;
                        }
                        left++;
                    }
                }
            }
            ans = max(ans , right-left+1);
            right++;



        }
        return ans;
    }
};