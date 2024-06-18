class Solution {
private:
int solve(vector<int> &nums , int n){
    // vector<vector<int>> dp(n+1 , vector<int>(n+1,0));
    vector<int> nextrow(n+1 , 0);
    vector<int> currrow(n+1,0);
    // if(curr==n){
    //     return 0;
    // }
    // if(dp[curr][prev+1] !=-1){
    //     return dp[curr][prev+1];
    // }
    for(int curr = n-1 ; curr>=0 ; curr--){
        for(int prev = n-1 ; prev>=-1 ; prev--){
            int inc =0;
            int exc=0;
            if(prev == -1 || nums[curr]>nums[prev]){
                inc = 1+nextrow[curr+1];
            }
            exc = nextrow[prev+1];
            currrow[prev+1]=max(inc,exc);
            // return dp[curr][prev];
        }
        nextrow = currrow;
    }
    return nextrow[0];
}
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n ,vector<int>(n+1,-1));
        return solve(nums,n);
    }
};