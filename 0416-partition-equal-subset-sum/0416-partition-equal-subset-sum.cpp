class Solution {
private:
bool solve(vector<int> &nums , int target,int n){
    vector<vector<int>> dp(n+1,vector<int>(target+1 , 0));
    for(int i=0 ; i<n ; i++){
        dp[i][0]=1;
    }
    for(int index = n-1 ; index>=0 ;index--){
        for(int temp=1;temp<=target ; temp++){
            bool inc = 0;
            if(temp-nums[index]>=0){
                inc = dp[index+1][temp-nums[index]];
            }
            bool exc = dp[index+1][temp];
            dp[index][temp]=inc||exc;
        }
    }
    return dp[0][target];

}
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0 ; i<nums.size() ; i++){
            sum = sum+nums[i];
        }
        if(sum%2==1){
            return 0;
        }
        else{
            return solve(nums,sum/2,nums.size());
        }
    }
};