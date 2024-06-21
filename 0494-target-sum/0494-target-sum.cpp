class Solution {
private:
int solve(vector<int> &nums , int target , int index , int n,unordered_map<int,int> dp[]){
    if(target==0 && index==n){
        return 1;
    }
    if(index>=n){
        return 0;
    }
    if(dp[index].count(target)){
        return dp[index][target];
    }
    int plus = solve(nums,target-nums[index] , index+1 , n,dp);
    int minus = solve(nums,target+nums[index],index+1 , n,dp);
    dp[index][target]=plus+minus;
    return dp[index][target] ;

}

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> dp[22];
        return solve(nums,target,0,n,dp);
    }
};