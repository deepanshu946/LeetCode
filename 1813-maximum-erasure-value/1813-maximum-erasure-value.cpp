class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int ans = INT_MIN;
        int sum = 0;
        unordered_set<int> s;
        while(right<nums.size()){
            if(s.find(nums[right]) != s.end()){
                int val = nums[right];
                while(nums[left] != val){
                    sum = sum - nums[left];
                    s.erase(nums[left]);
                    left++;
                }
                left++;
                right++;
            }
            else{
                sum = sum + nums[right];
                s.insert(nums[right]);
                right++;
                ans = max(ans , sum);
            }
        }
        return ans;
    }
};