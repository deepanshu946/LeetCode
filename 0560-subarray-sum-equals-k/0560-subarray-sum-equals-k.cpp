class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int prefix=0;
        m[0]=1;
        int ans = 0;
        for(int i=0 ; i<nums.size() ; i++){
            prefix=prefix+nums[i];
            ans = ans + m[prefix-k];
            m[prefix]++;
        }
        return ans;
    }
};