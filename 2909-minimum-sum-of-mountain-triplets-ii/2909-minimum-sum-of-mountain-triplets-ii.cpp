class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftmin(n,0);
        vector<int> rightmin(n,0);
        int mini = nums[0];
        for(int i=1 ; i<n ; i++){
            leftmin[i]=mini;
            mini= min(mini, nums[i]);
        }
        mini = nums[n-1];
        for(int i=n-2 ; i>=0; i--){
            rightmin[i]=mini;
            mini= min(mini, nums[i]);
        }
        int ans = INT_MAX;
        for(int i=1 ; i<n-1 ; i++){
            if(leftmin[i]<nums[i] && rightmin[i]<nums[i]){
                ans = min(ans , nums[i]+leftmin[i]+rightmin[i]);
            }
        }
        if(ans== INT_MAX){
            return -1;
        }
        return ans;
    }
};