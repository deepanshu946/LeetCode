class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int left=0;
        int right = 0;
        int prod = 1;
        if(k==0){
            return 0;
        }
        // for(int i=1 ; i<nums.size()-1; i++){
        //     if(nums[i]<k){
        //         ans++;
        //     }
        // }
        while(right<nums.size()){
            prod = prod*nums[right];
            while(left<right && left<nums.size() && prod >= k){
                prod = prod/nums[left];
                left++;
            }
            if(prod<k){
                ans +=  right - left + 1;
            }
            right++;
        }
        // ans = ans + (nums.size()-left-1);
        return ans;
    }
};