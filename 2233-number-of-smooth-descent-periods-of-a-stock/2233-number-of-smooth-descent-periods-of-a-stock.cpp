class Solution {
public:
    long long getDescentPeriods(vector<int>& nums) {
        // vector<long long> ans(nums.size(),1);
        int ans = 1;
        long long temp = 0;
        for(int i=1 ; i<nums.size(); i++){
            if(nums[i]==nums[i-1]-1){
                temp = temp + ans + 1;
                ans++;
            }
            else{
                ans = 1;
                temp++;
            }

        }
        return temp+1;

    }
};