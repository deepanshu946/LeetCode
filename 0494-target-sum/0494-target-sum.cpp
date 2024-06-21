class Solution {
private:
int solve(vector<int> &nums , int target , int index , int n){
    if(target==0 && index==n){
        return 1;
    }
    if(index>=n){
        return 0;
    }
    int plus = solve(nums,target-nums[index] , index+1 , n);
    int minus = solve(nums,target+nums[index],index+1 , n);
    return plus+minus ;

}

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(nums,target,0,n);
    }
};