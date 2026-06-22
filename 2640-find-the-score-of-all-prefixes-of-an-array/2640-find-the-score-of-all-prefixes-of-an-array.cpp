class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> ans;
        int count = 0;
        int maxi= 0;
        for(int i=0 ; i<nums.size() ; i++){
            maxi = max(maxi , nums[i]);
            ans.push_back(nums[i]+maxi);
        }
        int temp = ans[0];
        for(int i=1 ; i<ans.size() ; i++){
            ans[i]=ans[i]+ans[i-1];
        }
        return ans;
    }
};