class Solution {
public:
    long long maximumPoints(vector<int>& nums, int curr) {
        sort(nums.begin(), nums.end());
        if(curr<nums[0]){
            return 0;
        }
        curr = curr - nums[0];
        long long sum = 0;
        for(int i=1 ; i<nums.size() ; i++){
            sum = sum + nums[i];
        }
        sum = curr + sum;
        return 1+(sum/nums[0]);
    }
};