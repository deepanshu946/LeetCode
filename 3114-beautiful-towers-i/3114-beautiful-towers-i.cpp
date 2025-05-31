class Solution {
public:
    long long maximumSumOfHeights(vector<int>& nums) {
        long long ans = 0;
        for(int i=0 ; i<nums.size() ; i++){
            int peak = nums[i];
            long long temp = peak;
            long long left = peak;
            long long right = peak;

            for(int j=i-1 ; j>=0 ; j--){
                left = min((long long)left,(long long)nums[j]);
                temp = temp + left;
            }
            for(int j=i+1 ; j<nums.size() ; j++){
                right = min((long long)right , (long long)nums[j]);
                temp = temp + right;
            }
            ans = max((long long)ans ,(long long)temp);
        }
        return ans;
    }
};