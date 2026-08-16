class Solution {
public:
    int maximumLengthSubstring(string nums) {
        unordered_map<char,int> m;
        int left = 0;
        int right = 0;
        int ans = 0;
        while(right < nums.length()){
            m[nums[right]]++;
            if(m[nums[right]] > 2){
                while(left<right && m[nums[right]] > 2){
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