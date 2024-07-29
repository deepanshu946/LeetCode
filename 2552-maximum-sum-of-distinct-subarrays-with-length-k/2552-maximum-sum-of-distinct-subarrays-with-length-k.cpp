class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        long long ans = 0;
        long long sum = 0;
        int count = 0;
        for(int i=0 ; i<k ; i++){
            m[nums[i]]++;
            sum = sum+nums[i];
            if(m[nums[i]]==2){
                count++;
            }
        }
        if(count==0){
            ans = max(ans , sum);
        }
        int left = 0;
        int right = k;
        while(right<nums.size()){
            if(m[nums[left]]==2){
                count--;
            }
            m[nums[left]]--;
            
            sum = sum - nums[left];
            m[nums[right]]++;
            if(m[nums[right]]==2){
                count++;
            }
            sum = sum + nums[right];
            left++;
            right++;
            if(count==0){
                ans = max(ans , sum);
            }
        }
        return ans;
    }
};