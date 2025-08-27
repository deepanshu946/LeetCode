class Solution {
public:
    vector<bool> canEat(vector<int>& nums, vector<vector<int>>& queries) {
        vector<long long> pre(nums.size(),0);
        int n = nums.size();
        for(int i=1 ; i<n ; i++){
            pre[i]= pre[i-1]+nums[i-1];
        }
        vector<bool> ans;
         for (auto &q : queries) {
            int type = q[0];
            long long day = q[1] + 1; 
            long long cap = q[2];

            long long minEat = day;          
            long long maxEat = day * cap;

            long long start = pre[type] + 1;
            long long end = pre[type] + nums[type];

            if (maxEat >= start && minEat <= end) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};