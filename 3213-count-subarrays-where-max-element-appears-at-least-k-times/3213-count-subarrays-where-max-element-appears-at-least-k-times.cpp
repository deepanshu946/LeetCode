class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxx = 0;
        for(int i=0 ; i<nums.size() ; i++){
            maxx = max(maxx, nums[i]);
        }
        long long ans = 0;
        int left = 0;
        int right = 0;
        int count = 0;
        while(right<nums.size()){
            if(count>=k){
                while(left<right && count>=k){
                    ans = ans + nums.size()-right + 1;
                    if(nums[left] == maxx){
                        count--;
                    }
                    left++;

                }
            }
            else{
                if(nums[right]==maxx){
                    count++;
                }
                right++;
            }
        }
        if(count>=k){
                while(left<right && count>=k){
                    ans = ans + nums.size()-right + 1;
                    if(nums[left] == maxx){
                        count--;
                    }
                    left++;

                }
            }
            return ans;
    }
};