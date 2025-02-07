class Solution {
public:
    int totalFruit(vector<int>& nums) {
        unordered_map<int,int> m;
        int left = 0;
        int right = 0;
        int ans = 0;
        while(right<nums.size()){
            m[nums[right]]++;
                while(m.size() > 2){
                    m[nums[left]]--;
                    if(m[nums[left]]==0){
                        m.erase(nums[left]);
                    }
                    left++;
                }
            ans = max(ans , right-left+1);
            right++;
        }
        return ans;

    }
};