class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int right = 0;
        int left = 0;
        int ans = 0;

        while(right<nums.size()){
            m[nums[right]]++;
            if(m[nums[right]] > k){
                while(left<=right && m[nums[right]]>k){
                    m[nums[left]]--;
                    left++;
                }
            }
            else{
                ans = max(ans , right - left+1);
            }
            right++;
        }
        return ans;
    }
};