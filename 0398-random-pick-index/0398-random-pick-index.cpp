class Solution {
public:
    unordered_map<int,vector<int>> m;
    Solution(vector<int>& nums) {
        for(int i=0 ; i<nums.size() ; i++){
            m[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        vector<int> temp = m[target];
        int random = rand() % temp.size();
        return temp[random];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */