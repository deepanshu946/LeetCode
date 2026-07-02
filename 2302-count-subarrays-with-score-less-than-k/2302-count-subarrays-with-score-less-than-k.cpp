class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans= 0;
        int left=0;
        int right = 0;
        long long sum = 0;
        while(right < nums.size()){
            sum = sum + nums[right];
            while(left<right && sum*(right-left+1) >= k){
                sum = sum - nums[left];
                left++;
            }
            if(sum*(right-left+1)<k){
                ans = ans + right-left+1;
            }
            right++;
        }
        return ans;
    }
};