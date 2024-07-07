class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i + 1] != nums[i] && nums[i - 1] != nums[i] &&
                nums[i - 1] == nums[i + 1]) {
                ans++;
            }
        }
        if (nums[1] != nums[0] && nums[n - 1] != nums[0] &&
            nums[n - 1] == nums[1]) {
            ans++;
        }
        if (nums[0] != nums[n - 1] && nums[n - 2] != nums[n - 1] &&
            nums[n - 2] == nums[0]) {
            ans++;
        }
        return ans;
    }
};