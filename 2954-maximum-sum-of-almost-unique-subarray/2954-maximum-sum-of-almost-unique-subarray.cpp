class Solution {
public:
    long long maxSum(vector<int>& nums, int n, int k) {
        unordered_map<int,int> m;
        long long ans = 0;
        long long sum = 0;
        int count = 0;
        for(int i=0 ; i<k ; i++){
            m[nums[i]]++;
            sum = sum+nums[i];
            if(m[nums[i]]>1){
                count++;
            }
        }
        if(k-count >= n){
            ans = max(ans , sum);
        }
        int left = 0;
        int right = k;
        while(right<nums.size()){
            if(m[nums[left]]>1){
                count--;
            }
            m[nums[left]]--;
            
            sum = sum - nums[left];
            m[nums[right]]++;
            if(m[nums[right]]>1){
                count++;
            }
            sum = sum + nums[right];
            left++;
            right++;
            if(k-count >= n){
                ans = max(ans , sum);
            }
        }
        return ans;
    }
};