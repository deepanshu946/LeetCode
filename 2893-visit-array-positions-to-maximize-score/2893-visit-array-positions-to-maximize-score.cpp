class Solution {
private:
long long solve(int i , vector<int> &nums , int x , int par , vector<vector<long long>> &dp){
    if(i>=nums.size()){
        return 0;
    }
    if(dp[i][par] != -1){
        return dp[i][par];
    }
    // int ans = 0;
    // for(int j=i+1 ; j<nums.size() ; j++){
    //     if(nums[i]%2 == nums[j]%2 ){
    //         ans = max(ans , solve(j,nums,x));

    //     }
    //     else{
    //         ans = max(ans , solve(j,nums,x)-x);
    //     }
    // }
    long long inc;
    long long exc;
    if(nums[i]%2 == par){
        inc = nums[i] + solve(i+1,nums,x,nums[i]%2,dp); 
    
    }
    else{
        inc = nums[i]+solve(i+1,nums,x,nums[i]%2,dp)-x;
    }
    exc = solve(i+1,nums,x,par,dp);
    return dp[i][par]= max(inc,exc);
}
public:
    long long maxScore(vector<int>& nums, int x) {
        vector<vector<long long>> dp(nums.size()+1 , vector<long long>(2,-1));
        return nums[0]+solve(1,nums,x,nums[0]%2 , dp);
        // for(int i=nums.size()-1 ; i>=0 ; i--){
        //     long long ans = 0;
        //     for(int j=i+1 ; j<nums.size() ; j++){
        //         if(nums[i]%2 == nums[j]%2 ){
        //             ans = max(ans , dp[j]);

        //         }
        //         else{
        //             ans = max(ans , dp[j]-x);
        //         }
        //     }
        //     dp[i]= ans+nums[i];
        // }
        // return dp[0];
    }
};