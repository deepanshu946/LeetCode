class Solution {
public:
    long long getDescentPeriods(vector<int>& nums) {
        vector<long long> ans(nums.size(),1);
        long long temp = 0;
        for(int i=1 ; i<nums.size(); i++){
            if(nums[i]==nums[i-1]-1){
                ans[i]= ans[i-1]+1;
            }
            temp = temp + ans[i];

        }
        return temp+1;

    }
};