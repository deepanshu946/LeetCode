class Solution {
public:
    long long maximumPoints(vector<int>& nums, int curr) {
        // sort(nums.begin(), nums.end());
        long long sum = 0;
        int mini = INT_MAX;
        for(int i=0; i<nums.size() ; i++){
            sum = sum + nums[i];
            mini = min(mini,nums[i]);
        }
        if(curr<mini){
            return 0;
        }
        sum = sum - mini;
        curr = curr - mini;
        
        sum = curr + sum;
        return 1+(sum/mini);
    }
};